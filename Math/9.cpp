//
// Created by Ruohao L. on 05/03/2025.
//
class Solution
{
public:
    bool isPalindrome(int x)
    {
        // 负数不是回文数，结尾为 0（但不是 0 本身）的数字也不是
        if (x < 0 || x != 0 && x % 10 == 0) return false;

        int reversedHalf = 0;
        while (x > reversedHalf)
        // 只反转一半的数字
        {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // 如果是回文，x 应该等于 reversedHalf 或去掉最后一位后相等（奇数位情况）
        return x == reversedHalf || x == reversedHalf / 10;
    }
};

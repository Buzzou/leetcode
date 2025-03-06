//
// Created by Ruohao L. on 05/03/2025.
//
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int count = 0;
        while (n > 5)
        {
            count += n / 5; // 统计所有能整除5的数
            n /= 5; // 继续检查 25, 125, ...
        }
        return count;
    }
};

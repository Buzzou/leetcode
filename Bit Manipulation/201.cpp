//
// Created by Ruohao L. on 05/03/2025.
//
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int shift = 0;
        while (left != right)
            // 找到公共前缀
        {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift; // 补回右移的位数
    }
};

#include <cstdint>
//
// Created by Ruohao L. on 06/03/2025.
//
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;

        for (char i = 0; i < 32; i++)
        {
            // 左移相当于为下一位数字“腾出空间”
            // 即使最开始 result 为 0，左移也不会改变它的值，但这保证了后续的位能够正确地插入到低位
            result <<= 1; // 左移一位
            result |= n & 1; // 将 n 的最低位加入 result
            n >>= 1; // n 右移一位
        }
        return result;
    }
};

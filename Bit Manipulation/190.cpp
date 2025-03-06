//
// Created by Ruohao L. on 05/03/2025.
//
#include <algorithm>
#include <bitset>
#include <cstdint>
#include <string>
using namespace std;

class Solution
        // 每次调用函数时，都要进行字符串转换和反转操作，这会带来额外的时间和空间开销
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        // 将 n 转换为 32 位 bitset
        bitset<32> bs(n);
        // 得到其字符串表示（高位在前）
        string s = bs.to_string();
        // 反转字符串，得到低位在前
        reverse(s.begin(), s.end());
        // 将反转后的字符串转换回 bitset
        bitset<32> reversed(s);
        // 返回对应的无符号整数
        return static_cast<uint32_t>(reversed.to_ulong());
    }
};

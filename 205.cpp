//
// Created by Ruohao L. on 24/02/2025.
//
#include <string>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // 直接使用 数组 存储映射，比 unordered_map 更快，因为数组访问是 O(1) 常数时间，而 unordered_map 存在哈希冲突时可能会退化
        unsigned char s_to_t[256] = {0}, t_to_s[256] = {0};

        for (unsigned short i = 0; i < s.length(); ++i)
        {
            unsigned char a = s[i], b = t[i];

            if (s_to_t[a] && s_to_t[a] != b) return false;// 如果 s[i] 之前 已经映射过，那么它必须对应 t[i]
            if (t_to_s[b] && t_to_s[b] != a) return false;// 如果 t[i] 已经被别的字符映射过，则说明映射冲突，返回 false

            s_to_t[a] = b; // 如果是 isomorphic，那么 a 映射的一定是 b，不可能是后面的某个不是 b 的字母
            t_to_s[b] = a;
        }
        return true;
    }
};

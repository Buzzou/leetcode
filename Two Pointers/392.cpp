//
// Created by Ruohao L. on 23/02/2025.
//
#include <string>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        unsigned char i = 0;
        unsigned short j = 0;
        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j]) ++i; // 匹配成功，移动 s 的指针
            ++j; // 没有else，因为无论是否匹配，都要移动 t 指针
        }
        return i == s.size(); // i 走到了 s 末尾，说明匹配完成
    }
};

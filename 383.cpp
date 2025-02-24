//
// Created by Ruohao L. on 24/02/2025.
//
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, unsigned int> magMap; // 因为字母表只有 26 个小写字母，unordered_map 的大小是固定的
        // 统计 magazine 中每个字符的数量
        for (char c: magazine)
            magMap[c]++;

        // 检查 ransomNote 是否可以用 magazine 构造
        for (char c: ransomNote)
        {
            if (magMap[c] == 0)
                // 如果没有该字符或已用完，返回 false
                return false;
            --magMap[c]; // 使用一个字符
        }

        return true;
    }
};

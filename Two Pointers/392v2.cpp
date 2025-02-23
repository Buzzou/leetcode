//
// Created by Ruohao L. on 23/02/2025.
//
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     *
     * @param s 待查串（0 <= s.length <= 100 && s1, s2, ..., sk where k >= 109）
     * @param t 被查串（0 <= t.length <= 10^4）
     * @return return true if s is a subsequence of t, or false otherwise
     */
    bool isSubsequence(string s, string t)
    {
        // 1. 建立 t 中每个字符的索引位置的 哈希表 -> 这样可以 快速查找某个字符在 t 中出现的位置
        unordered_map<char, vector<int> > indexMap;

        for (unsigned short i = 0; i < t.size(); ++i)
        {
            indexMap[t[i]].push_back(i); // unordered_map允许相同first值存在
        }

        int prevIndex = -1; // 上一次匹配的字符在 t 里的位置

        for (char c: s)
        {
            if (indexMap.find(c) == indexMap.end()) return false; // t 中没有这个字符
            // 注：indexMap[c]：字符 c 在 t 中所有出现的位置（递增排序）
            // 找到 indexMap[c] 里 第一个大于 prevIndex 的位置，确保 s 的顺序不乱
            auto it = upper_bound(indexMap[c].begin(), indexMap[c].end(), prevIndex);
            if (it == indexMap[c].end()) return false; // 没有找到符合顺序的字符
            prevIndex = *it;
        }
        return true;
    }
};

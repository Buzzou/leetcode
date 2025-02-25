//
// Created by Ruohao L. on 24/02/2025.
//
#include <unordered_map>
#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> p_to_w;
        unordered_map<string, char> w_to_p;

        istringstream iss(s); // 用stringstream分割字符串
        string word;
        unsigned short i = 0; // s 里的单词数, 1 <= s.length <= 3000

        while (iss >> word)
        // 逐个提取单词
        {
            if (i >= pattern.size()) return false; // s 里的单词数 > pattern 长度

            char p = pattern[i];

            // 检查 pattern[i] -> word 映射
            if (p_to_w.count(p) && p_to_w[p] != word) return false;
            // 检查 word -> pattern[i] 映射
            if (w_to_p.count(word) && w_to_p[word] != p) return false;

            p_to_w[p] = word;
            w_to_p[word] = p;
            ++i;
        }

        return i == pattern.size(); // s 里的单词数 < pattern 长度
    }
};

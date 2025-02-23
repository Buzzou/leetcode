//
// Created by Ruohao L. on 22/02/2025.
//
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    // 判断所有字符串的前 mid 个字符是否相同
    bool isCommonPrefix(const vector<string>& strs, unsigned char midLen)
    {
        string prefix = strs[0].substr(0, midLen);

        for (unsigned char i = 1; i < strs.size(); ++i)
        {
            if (strs[i].substr(0, midLen) != prefix) return false;
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty()) return "";

        auto minStr = *min_element(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        // 二分查找最长公共前缀的长度
        unsigned char L = 0;
        unsigned char R = minStr.size();
        unsigned char midLen = (L + R) / 2;
        while (L <= R)
        {
            midLen = (L + R) / 2;
            if (isCommonPrefix(strs, midLen))
            {
                L = midLen + 1; // 试探更长前缀
            }
            else
            {
                R = midLen - 1; // 前缀太长，缩短
            }
        }

        return strs[0].substr(0, midLen);
    }
};

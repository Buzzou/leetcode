//
// Created by Ruohao L. on 23/02/2025.
//
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    static int lengthOfLongestSubstring(string s)
    {
        // 用 unordered_set 或 unordered_map（哈希表）存储窗口内的字符，快速查询是否重复
        unordered_map<char, int> lastIndex;
        unsigned short left = 0, maxLength = 0, right = 0;

        for (; right < s.length(); ++right)
        {
            char c = s[right];

            // 如果 c 在窗口内，则更新 left，缩小窗口
            if (lastIndex.find(c) != lastIndex.end() && lastIndex[c] >= left)
            {
                left = lastIndex[c] + 1;
            }

            // 更新字符最新位置
            lastIndex[c] = right;

            // 更新最大长度
            maxLength = max(maxLength, static_cast<unsigned short>(right - left + 1));
        }

        return maxLength;
    }
};

int main()
{
    string s = "abba";
    cout << Solution::lengthOfLongestSubstring(s) << endl; // 输出: 2
    return 0;
}

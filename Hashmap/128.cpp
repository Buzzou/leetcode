//
// Created by Ruohao L. on 25/02/2025.
//
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        unsigned int longest = 0;

        for (const auto num: numSet)
        {
            if (numSet.count(num - 1)) continue; // 只从序列起点开始扩展

            int currNum = num;
            unsigned int currLen = 1;

            while (numSet.count(currNum + 1))
            // 检查下一个数是否存在
            {
                ++currNum;
                ++currLen;
            }

            longest = max(longest, currLen);
        }

        return longest;
    }
};

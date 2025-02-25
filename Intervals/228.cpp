//
// Created by Ruohao L. on 25/02/2025.
//
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> result;
        if (nums.empty()) return result;

        char start = nums[0]; // 记录区间起点

        for (char i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1] + 1)
            // 当前数与前一个数不连续 -- 记录 [start, nums[i-1]] 的区间
            {
                if (start == nums[i - 1])
                    result.push_back(to_string(start));
                else
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));

                start = nums[i]; // 更新区间起点
            }
        }

        // 处理最后一个区间
        if (start == nums.back())
            result.push_back(to_string(start));
        else
            result.push_back(to_string(start) + "->" + to_string(nums.back()));

        return result;
    }
};

//
// Created by Ruohao L. on 04/03/2025.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);

        if (left == nums.end() || *left != target) return {-1, -1}; // 说明 target 不存在

        return {static_cast<int>(left - nums.begin()), static_cast<int>(right - nums.begin() - 1)};
    }
};

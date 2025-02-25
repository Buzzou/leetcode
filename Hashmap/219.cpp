//
// Created by Ruohao L. on 25/02/2025.
//
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_set<int> window;

        for (unsigned int i = 0; i < nums.size(); ++i)
        {
            if (window.count(nums[i])) return true; // 如果当前元素已经在窗口中，返回 true
            window.insert(nums[i]);
            if (window.size() > k)
            // 维持窗口大小
            {
                window.erase(nums[i - k]);
            };
        }
        return false;
    }
};

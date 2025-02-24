//
// Created by Ruohao L. on 24/02/2025.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> num_to_index;

        for (unsigned short i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            // 如果补数已经在哈希表里，直接返回
            if (num_to_index.count(complement)) return {num_to_index[complement], i};

            num_to_index[nums[i]] = i;
        }

        return {}; // 题目保证一定有解，这行不会执行
    }
};

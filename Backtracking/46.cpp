//
// Created by Ruohao L. on 04/03/2025.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int> > permute(vector<int>& nums)
    {
        sort(nums.begin(), nums.end()); // 确保从最小排列开始

        vector<vector<int> > result;

        do
        {
            result.push_back(nums);
        }
        while (next_permutation(nums.begin(), nums.end())); // 生成下一个排列

        return result;
    }
};

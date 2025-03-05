//
// Created by Ruohao L. on 05/03/2025.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
};

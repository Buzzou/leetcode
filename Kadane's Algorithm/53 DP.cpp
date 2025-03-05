//
// Created by Ruohao L. on 04/03/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxSum = nums[0];
        int currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            currentSum = max(currentSum + nums[i], nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

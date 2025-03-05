//
// Created by Ruohao L. on 05/03/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    int helper(vector<int>& nums, int left, int right)
    {
        if (left == right) return nums[left]; // 递归终止条件

        int mid = left + (right - left) / 2;
        int leftMax = helper(nums, left, mid);
        int rightMax = helper(nums, mid + 1, right);
        int crossMax = crossSum(nums, left, right, mid);

        return max({leftMax, rightMax, crossMax});
    }

    int crossSum(vector<int>& nums, int left, int right, int mid)
    {
        // 计算跨越中点的最大和
        int leftSum = INT_MIN, rightSum = INT_MIN;
        int sum = 0;

        // 从中间向左扩展
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        sum = 0;
        // 从中间向右扩展
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        return leftSum + rightSum;
    }
};

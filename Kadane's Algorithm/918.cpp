//
// Created by Ruohao L. on 04/03/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int totalSum = 0;
        int maxSum = nums[0], minSum = nums[0];
        int currentMax = 0, currentMin = 0;

        for (int num: nums)
        {
            totalSum += num; // 计算数组总和

            // Kadane’s Algorithm 计算最大子数组和
            currentMax = max(num, currentMax + num);
            maxSum = max(maxSum, currentMax);

            // Kadane’s Algorithm 计算最小子数组和
            currentMin = min(num, currentMin + num);
            minSum = min(minSum, currentMin);
        }

        // 特殊情况：如果 totalSum == minSum，说明数组全是负数，只能返回 maxSum
        if (totalSum == minSum) return maxSum;

        // 返回最大子数组和（考虑跨越两端的情况）
        return max(maxSum, totalSum - minSum);
    }
};

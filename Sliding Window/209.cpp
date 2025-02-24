//
// Created by Ruohao L. on 23/02/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int left = 0, right = 0; // 控制窗口的左右边界
        unsigned int sum = 0;
        int minLength = INT_MAX;

        while (right < nums.size())
        {
            sum += nums[right];

            while (sum >= target)
            // 尝试收缩窗口，直到 sum 再次 < target
            {
                minLength = min(minLength, right - left + 1); // 记录当前窗口长度，更新最小值 min_length
                sum -= nums[left++]; // left 右移，减少窗口大小，并更新 sum
            }

            ++right;
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};

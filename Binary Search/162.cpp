//
// Created by Ruohao L. on 04/03/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    // 只找「局部」峰值
    {
        if (nums.size() == 1) return 0; //如果 nums 只有一个元素，那它本身就是峰值，直接返回索引 0

        short left = 0, right = nums.size() - 1;

        while (left < right)
        // 终止条件是 left == right
        {
            short mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) right = mid; // 说明峰值在 mid 左侧或就是 mid
            else left = mid + 1; // 说明 mid 右侧有更大的值，因此峰值一定在右边
        }

        return left;
    }
};

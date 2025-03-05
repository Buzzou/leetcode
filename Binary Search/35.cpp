//
// Created by Ruohao L. on 04/03/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        short left = 0, right = nums.size() - 1;

        while (left <= right)
        // 只要左指针不超过右指针
        {
            short mid = left + (right - left) / 2; // 计算中间索引，避免溢出

            if (nums[mid] == target) return mid; // 找到目标值，直接返回索引
            else if (nums[mid] < target) left = mid + 1; // 目标值在右半部分
            else right = mid - 1; // 目标值在左半部分
        }

        return left; // 最终 left 指向 target 应该插入的位置
    }
};

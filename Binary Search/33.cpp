//
// Created by Ruohao L. on 04/03/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        short left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            short mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid; // 找到目标值，返回索引

            // 判断哪部分是有序的
            if (nums[left] <= nums[mid])
            // 左半部分有序
            {
                if (nums[left] <= target && target < nums[mid]) right = mid - 1; // 目标值在左半部分
                else left = mid + 1; // 目标值在右半部分
            }
            else
            // 右半部分有序
            {
                if (nums[mid] < target && target <= nums[right]) left = mid + 1; // 目标值在右半部分
                else right = mid - 1; // 目标值在左半部分
            }
        }

        return -1; // 没找到
    }
};

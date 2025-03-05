//
// Created by Ruohao L. on 04/03/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        short left = 0, right = nums.size() - 1;

        while (left < right)
        {
            short mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) left = mid + 1; // 最小值在右侧
            else right = mid; // 最小值在左侧或就是 mid
        }

        return nums[left]; // left == right 时，就是最小值
    }
};

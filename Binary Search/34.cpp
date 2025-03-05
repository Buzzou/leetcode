//
// Created by Ruohao L. on 05/03/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.empty()) return {-1, -1}; // 避免访问空数组

        int left = findLeft(nums, target);
        int right = findRight(nums, target);
        return {left, right};
    }

    int findLeft(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // 我们希望 left 最终停在 target 第一次出现的位置
            if (nums[mid] < target) left = mid + 1; // target 只能在右侧
                // 如果 nums[mid] == target，我们不会立即返回，而是继续向左搜索，直到找到 target 的最左端
            else right = mid - 1; // target 在左侧（包含可能的 mid）
        }
        // 要检查 left 是否越界 left < nums.size()，确保 target 确实存在
        // 例如：nums = [2, 2, 2]，target = 3，那么 left 最终会超出 nums.size()
        return (left < nums.size() && nums[left] == target) ? left : -1;
    }

    int findRight(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // 我们希望 right 最终停在 target 最后一次出现的位置
            if (nums[mid] <= target) left = mid + 1; // target 可能在 mid 右侧（包括 mid）
            else right = mid - 1; // target 在左侧
        }
        // 要检查 right 是否有效 (right >= 0)，确保 target 存在
        // 例如：nums = [2, 2, 2]，target = 1，那么 right = -1，此时说明 target 不存在
        return (right >= 0 && nums[right] == target) ? right : -1;
    }
};

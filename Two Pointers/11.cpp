//
// Created by Ruohao L. on 23/02/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * 2 <= height.length <= 10^5, 0 <= height[i] <= 10^4
     * @param height
     * @return
     */
    int maxArea(vector<int>& height)
    {
        // 1. 初始化双指针
        unsigned int left = 0, right = height.size() - 1; // 左右边界
        unsigned int maxArea = 0; // 存储最大面积

        while (left < right)
        // 4. 终止条件（最后套循环）
        {
            // 2. 计算当前面积，并更新最大值
            unsigned int area = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, area);

            // 3. 移动指针 -- 谁更短，谁移动！因为只有移动短边，才有可能让 min(height[left], height[right]) 变大，从而提高面积
            if (height[left] < height[right]) ++left;
            else --right;
        }
        return maxArea;
    }
};

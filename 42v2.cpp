//
// Created by Ruohao L. on 21/02/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        unsigned short length = height.size();
        if (length == 0) return 0;

        vector<int> left_max(length), right_max(length); //一算出来就预存
        left_max[0] = height[0];
        right_max[length - 1] = height[length - 1];

        // 计算 left_max
        for (unsigned short i = 1; i < length; ++i)
        {
            // 已经知道站在之前一步的时候左边最高的是多少了，再和自己比一下谁高就可以了
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        // 计算 right_max
        for (short i = length - 2; i >= 0; --i)
        {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        // 计算存水量
        unsigned int water = 0;
        for (unsigned short i = 0; i < length; ++i)
        {
            water += min(left_max[i], right_max[i]) - height[i];
        }

        return water;
    }
};

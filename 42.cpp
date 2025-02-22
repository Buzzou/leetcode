//
// Created by Ruohao L. on 21/02/2025.
//
//这种方法很多left_max 和 right_max被重复计算了，因为第一次被算出来没有保存->预存，减少重复计算
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        unsigned short length = height.size();
        unsigned int water = 0;

        for (unsigned short i = 0; i < length; ++i)
        {
            int left_max, right_max = 0;

            // 找左边最大值
            for (short j = i; j >= 0; --j)
            {
                left_max=max(left_max,height[j]);
            }

            // 找右边最大值
            for (short j=i;j<length;++j)
            {
                right_max=max(right_max,height[j]);
            }

            // 当前柱子能存的水
            water+=min(left_max,right_max)-height[i];
        }

        return water;
    }
};

//
// Created by Ruohao L. on 20/02/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int>& nums)
    {
        if (nums.empty() || nums.size() == 1) return 0;

        unsigned short current_end = 0; // 当前跳跃能到达的最远位置
        int current_max = 0; // 下一步能跳到的最远位置
        unsigned short jumps = 0; // 跳跃次数

        for (unsigned short i = 0; i < nums.size(); ++i)
        {
            // 身处每个元素，更新current_max为当前位置能跳到的最远位置
            current_max = max(current_max, i + nums[i]);

            // 当遍历到当前跳跃的终点时，表示当前跳跃已经处理完所有可能的位置，此时必须进行一次新的跳跃，并更新current_end为新的最远位置
            if (i == current_end)
            {
                jumps++; // 增加一次跳跃
                current_end = current_max; // 更新下一次跳跃的终点（选择了局部所有数中可以跳得最远的那一个）

                // 如果新的最远位置已经可以到达甚至超过数组末尾，提前退出
                if (current_end >= nums.size() - 1) break;
            }
        }
        return jumps;
    }
};

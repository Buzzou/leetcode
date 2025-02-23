//
// Created by Ruohao L. on 20/02/2025.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int maxReach = 0; // 当前能到达的最远位置
        for (unsigned short i = 0; i < nums.size(); ++i)
        {
            if (i > maxReach) return false; // 如果当前位置 i 超过了 maxReach，说明无法到达
            maxReach = max(maxReach, i + nums[i]); // 更新 maxReach
            if (maxReach >= nums.size() - 1) return true; // 如果能到最后，提前返回
        }
        return true; // for 循环完整执行完，没有触发 return false
    }
};

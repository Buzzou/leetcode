//
// Created by Ruohao L. on 25/02/2025.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int> >& points)
    {
        // 按 xend 升序排序
        ranges::sort(points, [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // 不要跟 map 混淆，不能写a.second()和b.second()
        });

        unsigned int arrows = 1;
        int arrowPos = points[0][1]; // 第一个气球的 end 作为第一支箭的位置

        for (const auto& balloon: points)
        {
            if (balloon[0] > arrowPos)
            // 当前箭无法覆盖新气球
            {
                ++arrows; // 需要额外射一箭
                arrowPos = balloon[1]; // 更新射箭点为当前气球的 end
            }
        }

        return arrows;
    }
};

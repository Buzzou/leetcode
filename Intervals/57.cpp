//
// Created by Ruohao L. on 25/02/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval)
    {
        vector<vector<int> > result;
        bool inserted = false;

        for (const auto& interval: intervals)
        {
            if (interval[1] < newInterval[0])
            // 当前区间在 newInterval 之前
            {
                result.push_back(interval);
            }
            else if (newInterval[1] < interval[0])
            // 当前区间在 newInterval 之后
            {
                if (!inserted)
                {
                    result.push_back(newInterval);
                    inserted = true;
                }
                result.push_back(interval);
            }
            else
            // 有重叠，合并区间
            {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
        }

        // 如果 `newInterval` 还没插入（它可能是最大的区间，一直在被min, max更新但从未有机会被插入）
        if (!inserted)
            result.push_back(newInterval);

        return result;
    }
};

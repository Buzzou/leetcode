//
// Created by Ruohao L. on 25/02/2025.
//
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals)
    {
        if (intervals.empty()) return {};

        // 先按照区间的 start 进行排序
        sort(intervals.begin(), intervals.end());

        vector<vector<int> > merged; // 0 <= starti <= endi <= 104
        unsigned short left = intervals[0][0], right = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= right)
            // 可以合并
            {
                right = max(right, static_cast<unsigned short>(intervals[i][1])); // 更新 right
            }
            else
            // 不能合并了，存入结果
            {
                merged.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        // 别忘了存入最后一个区间
        merged.push_back({left, right});

        return merged;
    }
};

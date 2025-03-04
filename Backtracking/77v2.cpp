//
// Created by Ruohao L. on 04/03/2025.
//
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    static vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > result;

        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1); // 生成 [1, 2, ..., n]

        vector<bool> select(n, false);
        fill(select.begin(), select.begin() + k, true); // 选择前 k 个

        do
        {
            vector<int> path;
            for (char i = 0; i < n; ++i)
            {
                if (select[i]) path.push_back(nums[i]);
            }
            result.push_back(path);
        }
        while (prev_permutation(select.begin(), select.end())); // 生成下一个排列

        return result;
    }
};

int main()
{
    int n = 4, k = 2;
    Solution::combine(n, k);
}

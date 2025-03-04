//
// Created by Ruohao L. on 04/03/2025.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int> > result;
        vector<int> path;
        backtrack(candidates, target, 0, 0, path, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, short target, short sum, short start, vector<int>& path,
                   vector<vector<int> >& result)
    {
        if (sum == target)
        // 找到一个组合
        {
            result.push_back(path);
            return;
        }
        if (sum > target) return; // 剪枝：和超过 target，返回

        for (short i = start; i < candidates.size(); ++i)
        {
            path.push_back(candidates[i]); // 选择当前数
            backtrack(candidates, target, sum + candidates[i], i, path, result); // 继续递归（i 不变，允许重复选取）
            path.pop_back(); // 回溯，撤销选择
        }
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> res = sol.combinationSum(candidates, target);

    for (const auto& v : res) {
        for (int num : v) cout << num << " ";
        cout << endl;
    }
}

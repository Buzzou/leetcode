//
// Created by Ruohao L. on 02/03/2025.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution
{
public:
    unordered_map<string, vector<pair<string, double> > > graph; // 存储图 -- graph["a"] = {{"b", 2.0}};  // a -> b 权重 2.0

    // **BFS 计算路径**
    double bfs(const string& start, const string& end)
    {
        // 1. **边界处理**：如果 start 或 end 不在图中，说明无解，直接返回 -1.0
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) return -1.0;

        queue<pair<string, double> > q; // BFS 队列，存 {当前变量, 到该变量的累计乘积}
        unordered_set<string> visited; // 记录访问过的变量，防止重复计算，避免死循环

        q.emplace(start, 1.0); // **起点 start，初始乘积为 1**
        visited.insert(start);

        // 2. **BFS 遍历**
        while (!q.empty())
        {
            auto [cur,value] = q.front(); // cur 是当前变量，value 是从 start 到 cur 的乘积
            q.pop();

            // **找到目标，直接返回结果**
            if (cur == end) return value;

            // 遍历当前节点的所有邻居 next
            for (auto& neighbor: graph[cur])
            {
                string next = neighbor.first; // 变量名
                const double weight = neighbor.second; // weight 是 cur / next 的值（即 cur → next 这条边的权重）

                if (!visited.count(next))
                // 确保 next 没访问过，否则会重复计算，可能导致死循环
                {
                    visited.insert(next);
                    q.emplace(next, value * weight); // 累计乘积：value * weight，即 start → cur → next 的路径权重
                }
            }
        }

        return -1.0; // **如果没有找到 end，返回 -1.0**
    }

    vector<double> calcEquation(const vector<vector<string> >& equations, const vector<double>& values,
                                const vector<vector<string> >& queries)
    {
        // **1. 建图**
        for (int i = 0; i < equations.size(); ++i)
        {
            string A = equations[i][0], B = equations[i][1];
            double val = values[i];

            graph[A].emplace_back(B, val);
            graph[B].emplace_back(A, 1.0 / val);
        }

        // **2. 处理查询**
        vector<double> result;
        for (auto& query: queries)
        {
            const string& C = query[0];
            const string& D = query[1];
            result.push_back(bfs(C, D));
        }

        return result;
    }
};

int main()
{
    Solution sol;
    /*
     * 等价于：
     * a --(2.0)--> b --(3.0)--> c
     * b --(0.5)--> a
     * c --(1/3.0)--> b
    */
    vector<vector<string> > equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string> > queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    vector<double> result = sol.calcEquation(equations, values, queries);
    /*
    * 查询 a / c 的过程：
    * 初始 q = {("a", 1.0)}
    * 从 a 访问 b，计算 1.0 * 2.0 = 2.0
    * 从 b 访问 c，计算 2.0 * 3.0 = 6.0
    * 找到 c，返回 6.0
     */

    for (double res: result)
    {
        cout << res << " ";
    }
    cout << endl;
}

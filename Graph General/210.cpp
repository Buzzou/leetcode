//
// Created by Ruohao L. on 02/03/2025.
//
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites)
    {
        vector<vector<short> > graph(numCourses); // 邻接表
        vector<short> indegree(numCourses, 0); // 记录每个课程的入度
        vector<int> order; // 存储拓扑排序的结果

        // **1. 构建邻接表 + 计算入度**
        for (auto& pre: prerequisites)
        {
            short a = pre[0], b = pre[1];
            graph[b].push_back(a); // b -> a
            indegree[a]++; // 课程 a 的入度 +1
        }

        // **2. 将所有入度为 0 的课程入队**
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0) q.push(i);
        }

        // **3. BFS 拓扑排序**
        short count = 0; // 记录能学完的课程数
        while (!q.empty())
        {
            short cur = q.front();
            q.pop();
            // count++;
            order.push_back(cur); // ✅ 记录修课顺序

            for (short next: graph[cur])
            // 如果有环，某些节点的入度永远不会变成 0，最终不会被访问到，count < numCourses
            {
                indegree[next]--; // 入度 -1
                if (indegree[next] == 0) q.push(next);
            }
        }
        if (order.size() == numCourses)
            return order; // 说明所有课程都能学完（全部加入过队列），否则说明有课程无法加入队列，说明存在环，返回 false
        return {};
    }
};

int main()
{
    Solution sol;

    vector<vector<int> > prerequisites1 = {{1, 0}};
    vector<vector<int> > prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<vector<int> > prerequisites3 = {};

    vector<int> res1 = sol.findOrder(2, prerequisites1);
    vector<int> res2 = sol.findOrder(4, prerequisites2);
    vector<int> res3 = sol.findOrder(1, prerequisites3);

    // 打印结果
    for (int course: res1) cout << course << " ";
    cout << endl;
    for (int course: res2) cout << course << " ";
    cout << endl;
    for (int course: res3) cout << course << " ";
    cout << endl;

    return 0;
}

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
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites)
    {
        vector<vector<short> > graph(numCourses); // 邻接表
        vector<short> indegree(numCourses, 0); // 记录每个课程的入度

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
            count++;

            for (short next: graph[cur])
            // 如果有环，某些节点的入度永远不会变成 0，最终不会被访问到，count < numCourses
            {
                indegree[next]--; // 入度 -1
                if (indegree[next] == 0) q.push(next);
            }
        }

        return count == numCourses; // 说明所有课程都能学完（全部加入过队列），否则说明有课程无法加入队列，说明存在环，返回 false
    }
};

int main()
{
    Solution sol;
    vector<vector<int> > prerequisites1 = {{1, 0}};
    vector<vector<int> > prerequisites2 = {{1, 0}, {0, 1}};

    cout << sol.canFinish(2, prerequisites1) << endl; // 输出: 1 (true)
    cout << sol.canFinish(2, prerequisites2) << endl; // 输出: 0 (false)

    return 0;
}

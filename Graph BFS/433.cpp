//
// Created by Ruohao L. on 03/03/2025.
//
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string>& bank)
    {
        unordered_set<string> bankSet(bank.begin(), bank.end()); // 把基因库存入哈希表，加速查找
        if (!bankSet.count(endGene)) return -1; // 目标基因不在库中，无法变换

        queue<pair<string, int> > q; // BFS 队列 (当前基因, 变换步数)
        unordered_set<string> visited; // 记录访问过的基因
        vector<char> choices = {'A', 'C', 'G', 'T'}; // 可用字符

        q.push({startGene, 0});
        visited.insert(startGene);

        while (!q.empty())
        {
            auto [gene, steps] = q.front();
            q.pop();

            // 如果找到目标基因，返回步数
            if (gene == endGene) return steps;

            // 生成所有可能的下一步变换
            for (char i = 0; i < 8; ++i)
            {
                char original = gene[i]; // 记录原字符
                for (char c: choices)
                {
                    if (c == original) continue; // 避免替换相同字符

                    gene[i] = c; // 变换字符
                    if (bankSet.count(gene) && !visited.count(gene))
                    {
                        q.push({gene, steps + 1});
                        visited.insert(gene); // 标记访问
                    }
                }
                gene[i] = original; // 还原基因
            }
        }

        return -1;
    }
};

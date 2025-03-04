//
// Created by Ruohao L. on 03/03/2025.
//
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int snakesAndLadders(vector<vector<int> >& board)
    {
        short n = board.size();
        vector<int> cells(n * n + 1, 0); // cells[i] 来存储编号为 i 的格子，而 cells[0] 并不会被使用
        bool leftToRight = true;
        char idx = 1;

        // 1. 构造一维数组 cells
        for (char row = n - 1; row >= 0; --row)
        {
            if (leftToRight)
            {
                for (char col = 0; col < n; ++col)
                {
                    cells[idx] = board[row][col] == -1 ? idx : board[row][col];
                    idx++;
                }
            }
            else
            {
                for (char col = n - 1; col >= 0; --col)
                {
                    cells[idx] = board[row][col] == -1 ? idx : board[row][col];
                    idx++;
                }
            }
            leftToRight = !leftToRight;
        }

        // 2. BFS 搜索最短路径
        queue<int> q;
        vector<bool> visited(n * n + 1, false);
        q.push(1);
        visited[1] = true;
        short steps = 0;

        while (!q.empty())
        {
            short size = q.size();
            while (size--)
            {
                short curr = q.front();
                q.pop();
                if (curr == n * n) return steps; // 到达终点

                // 进行 1~6 的掷骰子选择
                for (char dice = 1; dice <= 6; ++dice)
                {
                    short next = curr + dice;
                    if (next > n * n) break; // 超出范围

                    next = cells[next]; // 如果是梯子/蛇，则跳转
                    if (!visited[next])
                    {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            steps++;
        }

        return -1; // 不能到达终点
    }
};

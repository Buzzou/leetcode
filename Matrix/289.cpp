//
// Created by Ruohao L. on 24/02/2025.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static void gameOfLife(vector<vector<int> >& board)
    {
        unsigned char m = board.size(), n = board[0].size(); // 1 <= m, n <= 25
        vector<char> dirs = {-1, 0, 1}; // 用于遍历 8 个方向

        // 1. 计算下一代状态，用 2 和 -1 作为标记
        for (unsigned char i = 0; i < m; ++i)
        {
            for (unsigned char j = 0; j < n; ++j)
            {
                // 对于每一个棋盘格
                unsigned char liveNeighbors = 0;
                // 均遍历 8 个方向
                for (char di: dirs)
                {
                    for (char dj: dirs)
                    {
                        if (0 == di && 0 == dj) continue;
                        char ni = i + di, nj = j + dj;
                        if ((ni >= 0 && ni < m) && (nj >= 0 && nj < n) && (board[ni][nj] == 1 || board[ni][nj] == 2))
                            ++liveNeighbors;
                    }
                }

                // 应用规则
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3))
                    board[i][j] = 2; // 1->2 活细胞变死
                if (board[i][j] == 0 && liveNeighbors == 3)
                    board[i][j] = -1; // 0->-1 死细胞变活
            }
        }

        // 2. 还原状态
        for (unsigned char i = 0; i < m; ++i)
        {
            for (unsigned char j = 0; j < n; ++j)
            {
                if (board[i][j] == 2) { board[i][j] = 0; }
                if (board[i][j] == -1) { board[i][j] = 1; }
            }
        }
    }
};

int main()
{
    vector<vector<int> > board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    Solution::gameOfLife(board);
    for (unsigned char i = 0; i < board.size(); ++i)
    {
        for (unsigned char j = 0; j < board[0].size(); ++j)
        {
            cout << board[i][j] << " ";
        }
    }
}

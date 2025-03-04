//
// Created by Ruohao L. on 02/03/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<char> >& board, int i, int j)
    {
        short m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;

        board[i][j] = '#'; // 先标记成 #，表示这个 O 不能被包围
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char> >& board)
    {
        short m = board.size(), n = board[0].size();
        if (m == 0 || n == 0) return;

        // 1. 先从边界的 'O' 开始，标记所有不能被包围的 'O' 为 '#'
        for (short i = 0; i < m; i++)
        {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }
        for (short j = 0; j < n; j++)
        {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }

        // 2. 遍历整个网格，把剩下的 'O' 变成 'X'，然后把 '#' 变回 'O'
        for (short i = 0; i < m; i++)
        {
            for (short j = 0; j < n; j++)
            {
                if (board[i][j] == 'O') board[i][j] = 'X'; // 这些是被包围的
                if (board[i][j] == '#') board[i][j] = 'O'; // 还原未被包围的
            }
        }
    }
};

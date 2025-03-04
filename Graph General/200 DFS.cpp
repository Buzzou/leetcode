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
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '0') return;

        board[i][j] = '0'; // 标记为访问过
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    int numIslands(vector<vector<char> >& grid)
    {
        short count = 0;
        short m = grid.size(), n = grid[0].size();

        for (short i = 0; i < m; i++)
        {
            for (short j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

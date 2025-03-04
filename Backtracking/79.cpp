//
// Created by Ruohao L. on 04/03/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char> >& board, string word)
    {
        char m = board.size(), n = board[0].size();

        // 遍历每个格子作为起点
        for (char i = 0; i < m; i++)
        {
            for (char j = 0; j < n; j++)
            {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char> >& board, string& word, char i, char j, char index)
    {
        if (index == word.size()) return true; // 找到完整单词，返回 true
        // 越界或不匹配(board[i][j] != word[index])
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) return false;

        char temp = board[i][j]; // 备份当前格子
        board[i][j] = '#'; // 标记已访问（避免重复使用）

        // 四个方向搜索 -- 向 上、下、左、右 递归
        bool found = dfs(board, word, i + 1, j, index + 1) || dfs(board, word, i - 1, j, index + 1) ||
                dfs(board, word, i, j + 1, index + 1) || dfs(board, word, i, j - 1, index + 1);

        board[i][j] = temp; // 恢复现场，确保其他路径不会被影响
        return found;
    }
};

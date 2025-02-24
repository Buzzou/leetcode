//
// Created by Ruohao L. on 24/02/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int> >& matrix)
    {
        unsigned char n = matrix.size(); // 1 <= n <= 20

        // 1. 先对角线翻转（转置矩阵）
        for (unsigned char i = 0; i < n; ++i)
        {
            for (unsigned char j = i + 1; j < n; ++j) swap(matrix[i][j], matrix[j][i]);
        }

        // 2. 再水平翻转（每行逆序）
        for (unsigned char i = 0; i < n; ++i) reverse(matrix[i].begin(), matrix[i].end());
    }
};

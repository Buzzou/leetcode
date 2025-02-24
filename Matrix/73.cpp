//
// Created by Ruohao L. on 24/02/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int> >& matrix)
    {
        vector<bool> rows(matrix.size(), false), cols(matrix[0].size(), false);

        // 1. 记录哪些行和列需要置零
        for (unsigned char i = 0; i < matrix.size(); ++i)
        {
            for (unsigned char j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        // 2. 置零
        for (unsigned char i = 0; i < matrix.size(); ++i)
        {
            for (unsigned char j = 0; j < matrix[0].size(); ++j)
                if (rows[i] || cols[j]) matrix[i][j] = 0;
        }
    }
};

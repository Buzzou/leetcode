//
// Created by Ruohao L. on 24/02/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
        if (matrix.empty()) return {};

        unsigned char m = matrix.size(); // 1 <= matrix.length <= 10, 行
        unsigned char n = matrix[0].size(); // 1 <= matrix[i].length <= 10, 列
        vector<int> result; // -100 <= matrix[i][j] <= 100

        char top = 0, bottom = m - 1, left = 0, right = n - 1;
        char dir = 0; // 方向索引，0=右，1=下，2=左，3=上

        while (top <= bottom && left <= right)
        {
            if (dir == 0)
            // → 向右
            {
                for (char i = left; i <= right; ++i) result.push_back(matrix[top][i]);
                ++top; // 缩小上边界
            }
            else if (dir == 1)
            {
                for (char i = top; i <= bottom; ++i) result.push_back(matrix[i][right]);
                --right; // 缩小右边界
            }
            else if (dir == 2)
            // ← 向左
            {
                for (char i = right; i >= left; --i) result.push_back(matrix[bottom][i]);
                --bottom; // 缩小下边界
            }
            else
            // ↑ 向上
            {
                for (char i = bottom; i >= top; --i) result.push_back(matrix[i][left]);
                ++left; // 缩小左边界
            }

            dir = (dir + 1) % 4; // 变换方向
        }
        return result;
    }
};

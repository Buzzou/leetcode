//
// Created by Ruohao L. on 23/02/2025.
//
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char> >& board)
    {
        vector<unordered_set<char> > rows(9), cols(9), boxes(9);

        for (int r = 0; r < 9; ++r)
        {
            for (int c = 0; c < 9; ++c)
            {
                char num = board[r][c];
                if (num == '.') continue;

                unsigned char box_index = (r / 3) * 3 + (c / 3); // 找到这个规律就可以替代很多个switch-case

                // 只要发现set里已经有过这个数了就false
                if (rows[r].count(num) || cols[c].count(num) || boxes[box_index].count(num)) return false;

                // 否则记下它出现过了
                rows[r].insert(num);
                cols[c].insert(num);
                boxes[box_index].insert(num);
            }
        }
        return true;
    }
};

//
// Created by Ruohao L. on 22/02/2025.
//
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || s.size() <= numRows) return s;

        vector<string> rows(numRows);
        unsigned short index = 0;
        char step = 1;

        for (char c: s)
        {
            rows[index] += c;
            if (index == numRows - 1) step = -1;
            else if (index == 0) step = 1;

            index += step;
        }

        string result = "";
        for (string row: rows)
        {
            result += row;
        }

        return result;
    }
};

//
// Created by Ruohao L. on 22/02/2025.
//
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<pair<int, string> > romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string result ="";

        for (const auto &[value, symbol] : romanMap)
        {
            while (num >= value)
            {
                result += symbol;
                num -= value;
            }
        }
        return result;
    }
};

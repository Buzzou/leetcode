//
// Created by Ruohao L. on 21/02/2025.
//
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, unsigned short> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        unsigned short result = 0;
        unsigned char length = s.length();

        for (unsigned char i = 0; i < length; ++i)
        {
            if ((romanMap[s[i]] < romanMap[s[i + 1]]) && (i < length - 1))
                result -= romanMap[s[i]];
            else
                result += romanMap[s[i]];
        }
        return result;
    }
};

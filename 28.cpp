//
// Created by Ruohao L. on 22/02/2025.
//
#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        auto result = haystack.find(needle);
        if (result != string::npos)
            return result;
        return -1;
    }
};

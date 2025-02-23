//
// Created by Ruohao L. on 23/02/2025.
//
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string filtered_string;

        for (const auto& c: s)
        {
            if (std::isalnum(c))
            {
                filtered_string += std::toupper(c);
            }
        }

        string reversed_string = filtered_string;
        reverse(filtered_string.begin(), filtered_string.end());

        if (filtered_string==reversed_string) return true;
        return false;
    }
};

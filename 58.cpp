//
// Created by Ruohao L. on 22/02/2025.
//
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        stringstream ss(s);
        string word;

        while (ss >> word)
        {
            ;
        }

        return word.size();
    }
};

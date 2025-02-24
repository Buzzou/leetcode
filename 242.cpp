//
// Created by Ruohao L. on 24/02/2025.
//
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length()) return false;

        unordered_map<wchar_t, int> freq;
        for (wchar_t c: s) freq[c]++;
        for (wchar_t c: t)
        {
            if (--freq[c] < 0) return false;
        }
        return true;
    }
};

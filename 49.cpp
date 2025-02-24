//
// Created by Ruohao L. on 24/02/2025.
//
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string> > groups;

        for (const string& s: strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        vector<vector<string> > result;
        for (auto& pair: groups) result.push_back(pair.second);

        return result;
    }
};

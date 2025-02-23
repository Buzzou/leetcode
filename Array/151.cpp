//
// Created by Ruohao L. on 22/02/2025.
//
#include <sstream>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution
{
public:
    static string reverseWords(string s)
    {
        stringstream ss(s);

        vector<string> words;
        string word;

        ostringstream oss;

        while (ss >> word) words.push_back(word);

        copy(words.rbegin(), words.rend(), ostream_iterator<string>(oss, " "));
        string result = oss.str();
        if (!result.empty()) result.pop_back();

        return result;
    }
};

int main()
{
    string s = "the sky is blue";
    Solution::reverseWords(s);
}

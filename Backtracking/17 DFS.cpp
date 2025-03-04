//
// Created by Ruohao L. on 03/03/2025.
//
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) return {};

        map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> result;
        string current;
        backtrack(digits, 0, phoneMap, current, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index, const map<char, string>& phoneMap, string& current,
                   vector<string>& result)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }

        char digit = digits.at(index);
        const string& letters = phoneMap.at(digit);

        for (char letter: letters)
        {
            current.push_back(letter);
            backtrack(digits, index + 1, phoneMap, current, result);
            current.pop_back(); // 回溯（撤销上一步的选择），继续尝试下一个可能的解
        }
    }
};

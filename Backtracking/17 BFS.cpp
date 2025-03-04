//
// Created by Ruohao L. on 04/03/2025.
//
//
// Created by Ruohao L. on 03/03/2025.
//
#include <map>
#include <vector>
#include <queue>
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

        queue<string> q;
        q.push("");

        for (char digit: digits)
        {
            int size = q.size();
            while (size--)
            {
                string curr = q.front();
                q.pop();
                for (char letter: phoneMap.at(digit))
                {
                    q.push(curr + letter);
                }
            }
        }

        vector<string> result;
        while (!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }
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

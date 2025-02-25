//
// Created by Ruohao L. on 25/02/2025.
//
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (const auto& c: s)
        {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else if (c == ')' && st.top() == '(') st.pop();
            else if (c == '}' && st.top() == '{') st.pop();
            else if (c == ']' && st.top() == '[') st.pop();
            else return false;
        }
        return true;
    }
};

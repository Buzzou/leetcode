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
            else
            {
                if (st.empty()) return false; // 避免 st.top() 在栈为空时访问
                if (c == ')' && st.top() == '(' || c == '}' && st.top() == '{' || c == ']' && st.top() == '[') st.pop();
                else return false;
            }
        }
        return st.empty(); // 如果栈非空，说明有未匹配的左括号
    }
};

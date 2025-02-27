//
// Created by Ruohao L. on 26/02/2025.
//
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;

        for (const auto token: tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                switch (token.at(0))
                {
                    case '+':
                    {
                        st.push(num1 + num2);
                        break;
                    }
                    case '-':
                    {
                        st.push(num1 - num2);
                        break;
                    }
                    case '*':
                    {
                        st.push(num1 * num2);
                        break;
                    }
                    case '/':
                    {

                        st.push(num1 / num2);
                        break;
                    }
                }
            }
            else
                st.push(stoi(token));
        }

        return st.top();
    }
};

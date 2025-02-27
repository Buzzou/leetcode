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
                switch (token.at(0))
                {
                    case '+':
                    {
                        auto addend2 = st.top();
                        st.pop();
                        auto addend1 = st.top();
                        st.pop();
                        st.push(addend1 + addend2);
                        break;
                    }
                    case '-':
                    {
                        auto subtrahend = st.top();
                        st.pop();
                        auto minuend = st.top();
                        st.pop();
                        st.push(minuend - subtrahend);
                        break;
                    }
                    case '*':
                    {
                        auto multiplier2 = st.top();
                        st.pop();
                        auto multiplier1 = st.top();
                        st.pop();
                        st.push(multiplier1 * multiplier2);
                        break;
                    }
                    case '/':
                    {
                        auto divisor = st.top();
                        st.pop();
                        auto dividend = st.top();
                        st.pop();
                        st.push(dividend / divisor);
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

//
// Created by Ruohao L. on 25/02/2025.
//
#include <string>
#include<sstream>
#include <stack>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        stringstream ss(path);
        string token;
        stack<string> st;

        // 按 '/' 分割路径
        while (getline(ss, token, '/'))
        {
            if (token == "." || token.empty()) continue; // 跳过空目录和当前目录
            if (token == "..")
            {
                if (!st.empty()) st.pop(); // ".." 代表返回上一级
            }
            else
                st.push(token); // 正常目录名压入栈
        }

        // 构造结果路径
        string result;
        while (!st.empty())
        {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }
};

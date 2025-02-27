//
// Created by Ruohao L. on 25/02/2025.
//
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> st; // 普通栈
    stack<int> minSt; // 维护最小值的栈

public:
    MinStack() {}

    void push(int val)
    {
        st.push(val);
        // 只有当 val 小于等于当前最小值时，才压入 minSt
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);
    }

    void pop()
    {
        // 如果当前出栈的元素是最小值，也要从 minSt 中移除
        if (!st.empty() && st.top() == minSt.top()) minSt.pop();
        st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return minSt.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//
// Created by Ruohao L. on 26/02/2025.
//
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
        // 链表结点在内存中不必存放在「连续的」内存空间中-->不能像数组一样通过下标访问
        // 链表可以用于表示由若干个（个数不定）「同类型」的元素所构成的具有线性结构的复合数据
        // 对链表结点的访问是通过头指针进行的，由头指针访问到链表的第一个结点，由第一个结点指针中的地址访问到第二个结点···以此类推
{
    int val; // 数据本身
    ListNode* next; // 一个指针，存储着下一个结点的内存地址：指向链表中的下一个结点/结构体；最后一个结点的指针为 nullptr
    explicit ListNode(int x) : val(x), next(nullptr) {} // 构造函数，头指针初始状态下为空值（链表中没有结点）
}; // 一个结点

class Solution
{
public:
    static bool hasCycle(ListNode* head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        // 如果 fast 或 fast->next 变成 nullptr，说明无环
        {
            slow = slow->next; // slow 每次移动一步
            fast = fast->next->next; // fast 每次移动两步
            if (slow == fast) return true; // 如果快指针追上慢指针，说明有环（就像操场跑步，快的总会追上慢的）
        }
        return false; // fast 走到 nullptr，说明无环
    }
};

int main()
{
    // 创建链表 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3); // 产生一个动态变量来表示新结点，同时把 3 赋给新结点中表示结点值的成员
    ListNode* node2 = new ListNode(2);
    ListNode* node0 = new ListNode(0);
    ListNode* node_4 = new ListNode(-4);

    head->next = node2;
    node2->next = node0;
    node0->next = node_4;

    // 形成环: -4 -> 2
    node_4->next = node2; // pos = 1, 让-4指向2形成环

    if (Solution::hasCycle(head))
    {
        cout << "链表有环！" << endl;
    }
    else
    {
        cout << "链表无环！" << endl;
    }

    // 释放内存 (如果有环，这里不能简单删除，实际应用中需要先断开环)
    // 手动测试时，如果有环，可以跳过这部分避免无限循环
    node_4->next = nullptr; // 先断开环
    delete head;
    delete node2;
    delete node0;
    delete node_4;

    return 0;
}

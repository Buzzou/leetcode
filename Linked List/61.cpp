//
// Created by Ruohao L. on 27/02/2025.
//

#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head || !head->next || 0 == k) return head;

        // 1. 计算链表长度
        short len = 1;
        ListNode* tail = head; // 初始化尾节点
        while (tail->next)
        // 去找尾节点
        {
            tail = tail->next;
            len++;
        }

        // 处理 k % len == 0 的情况，直接返回原链表
        k = k % len;
        if (k == 0) return head;

        // 2. 形成环
        tail->next = head;

        // 3. 计算新的头部位置(0起算)
        short newHeadPos = len - k; // 计算新的头部索引
        auto newTail = head;

        for (short i = 0; i < newHeadPos - 1; i++) newTail = newTail->next; // 找到新尾巴

        // 4. 断开环，设置新头
        auto newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

// 辅助函数：创建链表
ListNode* createList(const std::initializer_list<int>& values)
{
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int val: values)
    {
        cur->next = new ListNode(val);
        cur = cur->next;
    }
    return dummy.next;
}

// 辅助函数：打印链表
void printList(ListNode* head)
{
    while (head)
    {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// 释放链表内存
void freeList(ListNode* head)
{
    while (head)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Solution solution;

    // 测试用例 1: 旋转 2 次
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    std::cout << "Original List: ";
    printList(head1);
    head1 = solution.rotateRight(head1, 2);
    std::cout << "Rotated List (k=2): ";
    printList(head1);
    freeList(head1);

    // 测试用例 2: 旋转 4 次
    ListNode* head2 = createList({0, 1, 2});
    std::cout << "Original List: ";
    printList(head2);
    head2 = solution.rotateRight(head2, 4);
    std::cout << "Rotated List (k=4): ";
    printList(head2);
    freeList(head2);

    return 0;
}

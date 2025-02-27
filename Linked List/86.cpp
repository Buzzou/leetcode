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
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* partition(ListNode* head, int x)
    {
        if (!head) return nullptr;

        // 虚拟头节点避免空指针处理，即便 small 或 large 为空，也能正确连接
        auto smallDummy = ListNode();
        auto largeDummy = ListNode();
        auto small = &smallDummy;
        auto large = &largeDummy;

        while (head)
        {
            if (head->val < x)
            {
                small->next = head;
                small = small->next;
            }
            else
            {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }

        small->next = largeDummy.next; // 连接 `small` 和 `large`
        large->next = nullptr; // 断开 `large` 链表的尾部，避免成环

        return smallDummy.next;
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

    // 测试用例 1
    ListNode* head1 = createList({1, 4, 3, 2, 5, 2});
    std::cout << "Original List: ";
    printList(head1);
    head1 = solution.partition(head1, 3);
    std::cout << "Partitioned List (x=3): ";
    printList(head1);
    freeList(head1);

    // 测试用例 2
    ListNode* head2 = createList({2, 1});
    std::cout << "Original List: ";
    printList(head2);
    head2 = solution.partition(head2, 2);
    std::cout << "Partitioned List (x=2): ";
    printList(head2);
    freeList(head2);

    return 0;
}

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
    explicit ListNode(const int x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    static ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        auto dummy = ListNode(); // 创建哑节点，方便处理 `left == 1` 的情况
        dummy.next = head;

        // 1. 找到 left 之前的 `prev` 节点
        auto prev = &dummy;
        for (short i = 1; i < left; ++i)
        // 如果 left == 1，这说明 prev 为空，反转部分需要从 head 开始
        // 那这样 prev 就需要是 虚拟头结点，所以我们需要使用 dummy
        {
            prev = prev->next;
        }

        // 2. 反转 [left, right] 之间的部分 -- 逐个反转
        // prev=1
        auto cur = prev->next; // cur=2
        for (short i = left; i < right; ++i)
        {
            auto next = cur->next; // 1. 记下2的下一个结点(3)的内存地址next
            cur->next = next->next; // 2. 让2的下一个结点的内存地址 `2->next` 改为 `4` 的内存地址：prev → 1 → 2 → 4 → 5
            next->next = prev->next; // 3. 把3的下一个结点的内存地址 `3->next` 改为 `prev` 的内存地址
            prev->next = next; //4. 让 `prev` 的下一个结点的内存地址更新为next(3)的内存地址，保持新顺序
        }


        return dummy.next;
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

    // 测试用例 1: 反转 [2,4]
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    std::cout << "Original List: ";
    printList(head1);
    head1 = solution.reverseBetween(head1, 2, 4);
    std::cout << "Reversed List (2,4): ";
    printList(head1);
    freeList(head1);

    // 测试用例 2: 反转整个链表
    ListNode* head2 = createList({1, 2, 3, 4, 5});
    std::cout << "Original List: ";
    printList(head2);
    head2 = solution.reverseBetween(head2, 1, 5);
    std::cout << "Reversed List (1,5): ";
    printList(head2);
    freeList(head2);

    // 测试用例 3: 只有一个元素，反转无变化
    ListNode* head3 = createList({5});
    std::cout << "Original List: ";
    printList(head3);
    head3 = solution.reverseBetween(head3, 1, 1);
    std::cout << "Reversed List (1,1): ";
    printList(head3);
    freeList(head3);

    return 0;
}

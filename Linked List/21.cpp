//
// Created by Ruohao L. on 26/02/2025.
//

#include <initializer_list>
#include <iostream>

//Definition for singly-linked list.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode dummy = ListNode(0); // 它将来的 next 会指向新链表的第一个节点
        ListNode* cur = &dummy; // 下面将使用 cur 指针遍历

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        cur->next = list1 ? list1 : list2; // 直接连接剩余的非空链表
        return dummy.next; // 返回合并后链表的头
    }
};

// 辅助函数：根据 initializer_list 创建链表，返回头指针
ListNode* createList(const std::initializer_list<int>& values)
{
    ListNode dummy;
    ListNode* cur = &dummy;
    for (int val: values)
    {
        cur->next = new ListNode(val);
        cur = cur->next;
    }
    return dummy.next;
}

// 辅助函数：打印链表，方便调试
void printList(ListNode* head)
{
    while (head)
    {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// 释放链表内存，防止内存泄漏（适用于本地运行）
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
    ListNode* list1 = createList({1, 2, 4});
    ListNode* list2 = createList({1, 3, 4});
    std::cout << "List 1: ";
    printList(list1);
    std::cout << "List 2: ";
    printList(list2);

    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
    std::cout << "Merged List: ";
    printList(mergedList);

    // 释放内存
    freeList(mergedList);

    return 0;
}

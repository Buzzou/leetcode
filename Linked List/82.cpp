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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head) return nullptr;

        auto dummy = ListNode(0, head); // 哨兵节点
        auto prev = &dummy; // `prev` 指向上一个唯一节点
        auto curr = head;

        while (curr)
        {
            // 如果 `curr->next` 存在，并且 `curr->val` 和 `curr->next->val` 相同
            if (curr->next && curr->val == curr->next->val)
            {
                // 跳过所有相同值的节点
                while (curr->next && curr->val == curr->next->val)
                {
                    auto temp = curr;
                    curr = curr->next;
                    delete temp; // 释放内存
                }
                // `curr` 现在指向最后一个重复项，跳过它
                prev->next = curr->next;
                delete curr; // 释放 `curr`
            }
            else
            {
                // 没有重复，`prev` 前进
                prev = curr;
            }
            curr = prev->next; // 继续遍历
        }

        return dummy.next;
    }
};

// 辅助函数：创建链表
ListNode* createList(const std::initializer_list<int>& values) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int val : values) {
        cur->next = new ListNode(val);
        cur = cur->next;
    }
    return dummy.next;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// 释放链表内存
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;

    // 测试用例 1: 删除所有重复项
    ListNode* head1 = createList({1, 2, 3, 3, 4, 4, 5});
    std::cout << "Original List: ";
    printList(head1);
    head1 = solution.deleteDuplicates(head1);
    std::cout << "After Removing Duplicates: ";
    printList(head1);
    freeList(head1);

    // 测试用例 2: 只有重复值，结果为空
    ListNode* head2 = createList({1, 1, 1, 2, 3});
    std::cout << "Original List: ";
    printList(head2);
    head2 = solution.deleteDuplicates(head2);
    std::cout << "After Removing Duplicates: ";
    printList(head2);
    freeList(head2);

    return 0;
}

//
// Created by Ruohao L. on 27/02/2025.
//

#include <iostream>
// Definition for singly-linked list.
// 不能直接用 std::list，因为 ListNode* 是裸指针实现的单链表，没有 STL 提供的 size()，也没有 erase()，只能自己遍历找到要删除的节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        auto dummy = ListNode(0, head); // 哑节点，避免删除头节点时特判
        auto fast = &dummy;
        auto slow = &dummy;

        // 1. `fast` 先前进 `n + 1` 步，而 `slow` 就暂时原地不动指向待删除节点的前一个
        for (char i = 0; i < n + 1; i++)
        {
            fast = fast->next;
        }

        // 2. `fast` 和 `slow` 一起走，直到 `fast` 到达 `nullptr`，此时 `slow` 恰好指向待删除节点的前一个
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // 3. `slow->next` 是要删除的节点，跳过它
        auto toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete; // 释放内存

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

    // 测试用例 1: 删除倒数第 2 个节点
    ListNode* head1 = createList({1, 2, 3, 4, 5});
    std::cout << "Original List: ";
    printList(head1);
    head1 = solution.removeNthFromEnd(head1, 2);
    std::cout << "After Removing 2nd from End: ";
    printList(head1);
    freeList(head1);

    // 测试用例 2: 删除倒数第 1 个节点
    ListNode* head2 = createList({1, 2});
    std::cout << "Original List: ";
    printList(head2);
    head2 = solution.removeNthFromEnd(head2, 1);
    std::cout << "After Removing 1st from End: ";
    printList(head2);
    freeList(head2);

    return 0;
}

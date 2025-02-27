#include <iostream>
//
// Created by Ruohao L. on 26/02/2025.
//
//Definition for singly-linked list.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0); // 哨兵节点
        ListNode* cur = &dummy; // 指针用于构造结果链表
        char carry = 0; // 进位

        while (l1 || l2 || carry)
        {
            char sum = carry; // 先把上一轮的进位加到当前计算的数上

            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10; // 计算新的进位
            cur->next = new ListNode(sum % 10); // 取个位数存入新链表
            cur = cur->next;
        }

        return dummy.next;
    }
};

// 测试代码
int main()
{
    // 构造 l1 = [2,4,3]
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));

    // 构造 l2 = [5,6,4]
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution solution;
    const ListNode* result = solution.addTwoNumbers(l1, l2);

    // 输出结果
    while (result)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl; // 预期输出：7 0 8

    return 0;
}

//
// Created by Ruohao L. on 04/03/2025.
//

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
    ListNode* sortList(ListNode* head)
    {
        if (!head || !head->next) return head; // 递归终止条件（空链表或只有一个节点）

        ListNode* mid = findMiddle(head); // 找到中点
        ListNode* right = mid->next;
        mid->next = nullptr; // 断开链表，形成左右两部分

        ListNode* leftSorted = sortList(head); // 递归排序左半部分
        ListNode* rightSorted = sortList(right); // 递归排序右半部分

        return merge(leftSorted, rightSorted);// 归并两个已排序链表
    }

private:
    // 使用快慢指针找到链表的中间节点
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next; // 让 fast 先走一步，保证 slow 取的是中间偏左的点
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 归并两个有序链表
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0); // 哨兵节点
        ListNode* tail = &dummy; // 指向合并后链表的尾部

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // 连接剩余部分
        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};

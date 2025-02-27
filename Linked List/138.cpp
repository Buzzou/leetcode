//
// Created by Ruohao L. on 26/02/2025.
//
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> oldToNew;
        Node* cur = head;

        // 1. 创建所有新节点并建立映射
        while (cur)
        {
            oldToNew[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // 2. 赋值 next 和 random 指针
        cur=head;
        while (cur)
        {
            oldToNew[cur]->next = oldToNew[cur->next];// 可能为 nullptr
            oldToNew[cur]->random = oldToNew[cur->random];// 可能为 nullptr
            cur = cur->next;
        }

        return oldToNew[head];
    }
};

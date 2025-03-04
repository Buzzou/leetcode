//
// Created by Ruohao L. on 28/02/2025.
//
// Definition for a Node.
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node* connect(Node* root)
    {
        if (root == nullptr) return nullptr;
        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();
            Node* prev = nullptr; // 这里不能用 auto

            for (short i = 0; i < levelSize; i++)
            {
                Node* node = q.front();
                q.pop();

                // 连接当前节点的 next 指针
                if (prev) prev->next = node;
                prev = node;

                // 把左右子节点加入队列
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // 本层最后一个节点的 next 指向 NULL
            prev->next = nullptr;
        }

        return root;
    }
};

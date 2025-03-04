//
// Created by Ruohao L. on 01/03/2025.
//
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        if (!root) return {};

        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            const char levelSize = q.size();
            char rightMostValue = 0;

            for (char i = 0; i < levelSize; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                // 记录当前层的最后一个节点的值
                rightMostValue = node->val;

                // 先入队左子树，再入队右子树
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(rightMostValue);
        }

        return result;
    }
};

//
// Created by Ruohao L. on 02/03/2025.
//

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
    short count = 0; // 计数器，记录访问的节点数量
    short result = -1; // 结果值

    void inOrder(TreeNode* node, int k)
    {
        if (!node || count > k) return;

        inOrder(node->left, k); // 递归左子树

        count++; // 当前节点访问到了
        if (count == k) // 找到第 k 小的节点 (1-indexed)
        {
            result = node->val;
            return;
        }

        inOrder(node->right, k); // 递归右子树
    }

    int kthSmallest(TreeNode* root, int k)
    {
        inOrder(root, k);
        return result;
    }
};

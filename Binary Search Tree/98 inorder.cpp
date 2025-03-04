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
    TreeNode* prev = nullptr; // 记录前一个访问的节点

    bool inOrder(TreeNode* node)
    {
        if (!node) return true;

        // 递归检查左子树
        if (!inOrder(node->left)) return false;

        // **检查是否满足递增**
        if (prev && prev->val >= node->val) return false;
        prev = node; // 更新 prev

        // 递归检查右子树
        return inOrder(node->right);
    }

    bool isValidBST(TreeNode* root)
    {
        return inOrder(root);
    }
};

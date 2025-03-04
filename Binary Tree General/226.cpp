//
// Created by Ruohao L. on 28/02/2025.
//
#include <utility>

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
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root) return nullptr; // 终止条件

        // 交换左右子树
        std::swap(root->left, root->right);

        // 递归处理左右子树
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

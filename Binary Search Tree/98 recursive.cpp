//
// Created by Ruohao L. on 02/03/2025.
//
#include <climits>

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
    bool isValidBSTHelper(TreeNode* node, long min, long max)
    {
        if (!node) return true;

        // **检查当前节点是否在合法范围内**
        if (node->val <= min || node->val >= max) return false;

        // **递归检查左右子树**
        return isValidBSTHelper(node->left, min, node->val) && isValidBSTHelper(node->right, node->val, max);
    }

    bool isValidBST(TreeNode* root)
    {
        return isValidBSTHelper(root,LONG_MIN, LONG_MAX);
    }
};

//
// Created by Ruohao L. on 28/02/2025.
//

#include <algorithm>

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
    int maxDepth(TreeNode* root)
    {
        if (!root) return 0; // 递归终止条件

        unsigned short leftDepth = maxDepth(root->left);
        unsigned short rightDepth = maxDepth(root->right);

        return std::max(leftDepth, rightDepth) + 1; // 取较大值+1
    }
};

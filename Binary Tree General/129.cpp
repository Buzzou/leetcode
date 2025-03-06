//
// Created by Ruohao L. on 28/02/2025.
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
    int sumNumbers(TreeNode* root, int currentSum = 0)
    {
        if (!root) return 0;

        currentSum = currentSum * 10 + root->val;

        // 如果是叶子节点，返回这条路径的数值
        if (!root->left && !root->right) return currentSum;

        // 递归计算左右子树的总和
        return sumNumbers(root->left, currentSum) + sumNumbers(root->right, currentSum);
    }
};

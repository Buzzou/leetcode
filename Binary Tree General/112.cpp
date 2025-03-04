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
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (!root) return false;// 空树直接返回 false

        // 如果是叶子节点，检查是否刚好满足 targetSum
        if (root->left == nullptr && root->right == nullptr) return targetSum == root->val;

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

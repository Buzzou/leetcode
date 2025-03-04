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
    bool isMirror(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr) return true; // 两个都空，说明对称
        if (p == nullptr || q == nullptr) return false; // 只有一个空，说明不对称
        if (p->val != q->val) return false; // 值不同，不对称

        // 递归检查：左子树的左子树 vs 右子树的右子树，左子树的右子树 vs 右子树的左子树
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) return true; // 空树对称

        return isMirror(root->left, root->right);
    }
};

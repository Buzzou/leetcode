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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!p && !q) return true; // 都是空，说明相同
        if (!p || !q) return false; // 只有一个为空，说明不同
        if (p->val != q->val) return false; // 值不同，说明不同

        // 递归比较左右子树
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

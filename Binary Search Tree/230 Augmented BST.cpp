//
// Created by Ruohao L. on 02/03/2025.
//

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    short count; // 新增：以当前节点为根的子树节点个数(左子树的节点数+右子树的节点数+1)
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), count(1) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int kthSmallest(TreeNode* root, int k) {}
};

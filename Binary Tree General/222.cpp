//
// Created by Ruohao L. on 28/02/2025.
//

//Definition for a binary tree node.
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
    int countNodes(TreeNode* root)
    {
        if (!root) return 0;

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        // 如果左右高度相等，说明是满二叉树，可以直接用公式计算
        // 左移1位相当于乘以2，n位乘以 2^n
        if (leftHeight == rightHeight) return (1 << leftHeight) - 1;

        // 否则递归计算左右子树的节点数
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

private:
    int getLeftHeight(TreeNode* node)
    {
        int height = 0;
        while (node)
        {
            height++;
            node = node->left;
        }
        return height;
    }

    int getRightHeight(TreeNode* node)
    {
        int height = 0;
        while (node)
        {
            height++;
            node = node->right;
        }
        return height;
    }
};

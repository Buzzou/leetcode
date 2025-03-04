//
// Created by Ruohao L. on 02/03/2025.
//

#include <climits>
#include <algorithm>
using namespace std;

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
    int minDiff = INT_MAX;
    int prev = -1; // 记录上一个节点的值（初始为 -1，表示未初始化）

    void inorder(TreeNode* node)
    {
        if (!node) return;

        inorder(node->left);

        // 计算当前节点和前一个节点的差值
        if (prev != -1) minDiff = min(minDiff, node->val - prev);
        prev = node->val;

        inorder(node->right);
    }

    int getMinimumDifference(TreeNode* root)
    {
        inorder(root);
        return minDiff;
    }
};

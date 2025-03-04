//
// Created by Ruohao L. on 28/02/2025.
//

#include <algorithm>
#include <i386/limits.h>
#include <__algorithm/ranges_max.h>
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
    int maxSum = INT_MIN; // 记录全局最大路径和

    int maxGain(TreeNode* root)
    {
        if (!root) return 0;

        // 计算左、右子树的最大贡献值（如果贡献值 < 0，则直接舍弃，取 0）
        int leftGain = max(0, maxGain(root->left));
        int rightGain = max(0, maxGain(root->right));

        // 计算完整路径的最大值（可能的答案）
        int fullPathSum = root->val + leftGain + rightGain;

        // 更新「全局」最大路径和
        maxSum = max(maxSum, fullPathSum);

        // 返回当前节点的最大贡献值，用于父节点计算（只能选择左子树或右子树，因为路径不能分叉）
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root)
    {
        maxGain(root);
        //不是返回maxGain的return（递归函数的return并不是最终需要的结果），所以要单独写一个函数
        return maxSum;
    }
};

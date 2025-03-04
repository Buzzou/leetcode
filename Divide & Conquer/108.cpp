//
// Created by Ruohao L. on 04/03/2025.
//
#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildBST(vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr; // 递归终止条件

        short mid = (left + right) / 2; // 取中间值，避免整数溢出
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, left, mid - 1); // 递归构造左子树
        root->right = buildBST(nums, mid + 1, right); // 递归构造右子树

        return root;
    }
};

//
// Created by Ruohao L. on 28/02/2025.
//
#include <vector>
#include <unordered_map>
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
    short postIndex; // 记录 postorder 遍历的位置
    unordered_map<int, int> inorderMap; // 记录 inorder 数组中的值 -> 索引

    TreeNode* buileTreeHelper(vector<int>& inorder, vector<int>& postorder, short left, short right)
    {
        if (left > right) return nullptr; // 递归终止条件

        // 取 postorder 当前索引的元素作为根
        short rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // 在 inorder 里找到根的位置
        short inorderIndex = inorderMap[rootVal];

        // 递归构造 **右子树**
        root->right = buileTreeHelper(inorder, postorder, inorderIndex + 1, right);

        // 递归构造 **左子树**
        root->left = buileTreeHelper(inorder, postorder, left, inorderIndex - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        postIndex = postorder.size() - 1; // 从 postorder 末尾开始（根节点）

        // 构造哈希表，记录 inorder 中每个值的索引
        for (short i = 0; i < inorder.size(); i++)
            inorderMap[inorder[i]] = i;

        return buileTreeHelper(inorder, postorder, 0, inorder.size() - 1);
    }
};

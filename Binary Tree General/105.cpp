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
    unordered_map<int, int> inorder_map; // 记录 inorder 数组中每个值的位置 -- 值 -> 位置
    unsigned short preorderIndex = 0; // 记录当前 preorder 遍历的索引

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, short left, short right)
    {
        if (left > right) return nullptr; // 终止条件：没有元素了

        // 取 preorder 当前索引的元素作为根
        const short rootVal = preorder[preorderIndex++];
        const auto root = new TreeNode(rootVal);

        // 在 inorder 里找到根的位置
        unsigned short inorderIndex = inorder_map[rootVal];

        // 递归构建左子树（inorder 左边部分）
        root->left = buildTreeHelper(preorder, inorder, left, inorderIndex - 1);

        // 递归构建右子树（inorder 右边部分）
        root->right = buildTreeHelper(preorder, inorder, inorderIndex + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        // 建立一个哈希表，快速查找 inorder 中的索引
        for (unsigned short i = 0; i < inorder.size(); i++)
        {
            inorder_map[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
    }
};

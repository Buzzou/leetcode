//
// Created by Ruohao L. on 28/02/2025.
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
    void flatten(TreeNode* root)
    // 规定 flatten 函数返回 void，意味着 不能创建新的 TreeNode，必须在原地修改树结构（in-place）
    {
        if (root == nullptr) return;

        vector<TreeNode*> nodes;
        preorder(root, nodes);

        for (unsigned short i = 1; i < nodes.size(); i++)
        {
            nodes[i - 1]->left = nullptr;
            nodes[i - 1]->right = nodes[i];
        }
    }

private:
    void preorder(TreeNode* root, vector<TreeNode*>& nodes)
    {
        if (root == nullptr) return;
        nodes.push_back(root); // 先访问根
        preorder(root->left, nodes); // 递归遍历左子树
        preorder(root->right, nodes); // 递归遍历右子树
    }
};

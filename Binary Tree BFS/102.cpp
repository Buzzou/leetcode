//
// Created by Ruohao L. on 01/03/2025.
//
#include <vector>
#include <queue>
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
    vector<vector<int> > levelOrder(TreeNode* root)
    {
        if (!root) return {}; // 空树返回空数组

        vector<vector<int> > result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            const short levelSize = q.size();
            vector<int> levelNodes; // 存储当前层的所有节点值

            for (short i = 0; i < levelSize; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                levelNodes.push_back(node->val); // 记录当前节点的值

                // 先入队左子节点，再入队右子节点
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(levelNodes); // 把当前层的值存入结果
        }
        return result;
    }
};

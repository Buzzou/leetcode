//
// Created by Ruohao L. on 01/03/2025.
//
#include <vector>
#include <queue>
#include <deque> // 用于双端队列
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root)
    {
        if (!root) return {}; // 空树返回空数组

        vector<vector<int> > result;
        queue<TreeNode*> q;
        q.push(root);
        bool isLeftToRight = true; // 控制方向

        while (!q.empty())
        {
            short levelSize = q.size();
            deque<char> levelNodes; // 用双端队列存储当前层的值

            for (short i = 0; i < levelSize; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if (isLeftToRight) levelNodes.push_back(node->val); // 从左到右存值
                else levelNodes.push_front(node->val); // 从右到左存值

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(vector<int>(levelNodes.begin(), levelNodes.end()));
            isLeftToRight = !isLeftToRight; // 翻转方向
        }
        return result;
    }
};

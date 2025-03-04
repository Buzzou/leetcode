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
    vector<double> averageOfLevels(TreeNode* root)
    {
        if (!root) return {}; // 空树返回空数组

        vector<double> result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            short levelSize = q.size();
            double sum = 0;

            for (short i = 0; i < levelSize; i++)
                // 每次 for 循环处理 当前层的所有节点，同时记得入队下一层的节点
            {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val; // 累加当前层的值

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(sum / levelSize); // 计算平均值并存入结果
        }
        return result;
    }
};

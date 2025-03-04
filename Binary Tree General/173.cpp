//
// Created by Ruohao L. on 28/02/2025.
//

#include <stack>
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

class BSTIterator
{
private:
    stack<TreeNode*> stk; // stack 里始终只存储 路径上的左子树节点，保证 O(h) 空间

    // 把当前节点的所有左子节点压入栈
    void pushLeftNodes(TreeNode* node)
    {
        while (node)
        {
            stk.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root)
    {
        pushLeftNodes(root); // 先压入根及左子树的所有节点
    }

    int next()
    {
        TreeNode* node = stk.top(); // 取栈顶节点（当前最小值）
        stk.pop();

        // 按需遍历，从而不需要提前存储整个遍历结果，仅当需要时才继续遍历右子树
        if (node->right) pushLeftNodes(node->right); // 处理右子树的左子节点

        return node->val; // 每次 next() 只处理当前节点
    }

    bool hasNext()
    {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

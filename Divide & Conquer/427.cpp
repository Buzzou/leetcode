//
// Created by Ruohao L. on 04/03/2025.
//
#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node()
    {
        // True if the node represents a grid of 1's or False if the node represents a grid of 0's
        val = false;
        // True if the node is a leaf node on the tree / if the current grid has the same value (i.e all 1's or all 0's)
        // or False if the node has four children / if the current grid has different values
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution
{
public:
    Node* construct(vector<vector<int> >& grid)
    {
        char n = grid.size();
        return build(grid, 0, 0, n);
    }

private:
    Node* build(vector<vector<int> >& grid, char x, char y, char size)
    {
        if (size == 1) return new Node(grid[x][y], true); // 只有 1 个元素时，直接创建叶子节点

        char newSize = size / 2;
        Node* topLeft = build(grid, x, y, newSize);
        Node* topRight = build(grid, x, y + newSize, newSize);
        Node* bottomLeft = build(grid, x + newSize, y, newSize);
        Node* bottomRight = build(grid, x + newSize, y + newSize, newSize);

        // 检查四个子节点是否可以合并成一个叶子节点
        // 如果 topLeft, topRight, bottomLeft, bottomRight 都是叶子 且值相同，那么这四个区域应该合并，否则四叉树结构会过度复杂
        // 否则对于全 1 或全 0 的网格，本来可以用 1 个节点表示，但代码会创建一棵完整的 log(n) 深度的四叉树
        // 这实际上也是递归终止条件的另一部分：如果可以合并，应该提前返回
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight
            ->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val)
        {
            char val = topLeft->val;

            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;

            return new Node(val, true);
        }

        // 不能合并，创建一个父节点
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};

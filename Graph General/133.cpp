//
// Created by Ruohao L. on 02/03/2025.
//
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node*> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution
{
public:
    unordered_map<Node*, Node*> cloned; // 记录已克隆的节点

    Node* cloneGraph(Node* node)
    {
        if (!node) return nullptr; // 空图返回 nullptr
        if (cloned.count(node)) return cloned[node]; // 如果已经克隆过，直接返回

        Node* newNode = new Node(node->val); // 创建新节点
        cloned[node] = newNode; // 记录克隆结果

        // 递归克隆所有邻居
        for (Node* neighbor: node->neighbors) newNode->neighbors.push_back(cloneGraph(neighbor));

        return newNode;
    }
};

// **打印图的 BFS 辅助函数** -- 如果用 DFS 打印，可能会重复访问已打印的节点，导致无限循环
void printGraph(Node* node)
{
    if (!node) return;

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        Node* cur = q.front();
        q.pop();

        cout << "Node " << cur->val << " -> { ";
        for (Node* neighbor: cur->neighbors)
        {
            cout << neighbor->val << " ";
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        cout << "}" << endl;
    }
}

int main()
{
    // **1. 手动创建无向图**
    //  图结构：
    //    1 -- 2
    //    |    |
    //    4 -- 3
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    cout << "Original Graph:" << endl;
    printGraph(node1);

    // **2. 克隆图**
    Solution solution;
    Node* clonedGraph = solution.cloneGraph(node1);

    cout << "\nCloned Graph:" << endl;
    printGraph(clonedGraph);

    return 0;
}

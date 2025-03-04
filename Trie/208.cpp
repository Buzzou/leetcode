//
// Created by Ruohao L. on 03/03/2025.
//
#include <string>
#include <vector>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode*> children;
    bool isEnd;

    TrieNode(): children(26, nullptr), isEnd(false) {}
};

class Trie
{
private:
    TrieNode* root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode* node = root;
        for (const auto &c : word)
        {
            if (node->children[c - 'a'] == nullptr)
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode* node = root;
        for (const auto &c : word)
        {
            if (node->children[c - 'a'] == nullptr)
                return false;
            node = node->children[c - 'a'];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode* node = root;
        for (const auto &c : prefix)
        {
            if (node->children[c - 'a'] == nullptr)
                return false;
            node = node->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

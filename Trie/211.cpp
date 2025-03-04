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

class WordDictionary
{
private:
    TrieNode* root;

    bool dfs(TrieNode* node, string& word, int index)
    {
        if (node == nullptr) return false;
        if (index == word.size()) return node->isEnd;

        char c = word[index];
        if (c == '.')
        // 遇到 '.' 需要匹配所有可能的子节点
        {
            for (const auto& child: node->children)
            {
                if (child != nullptr && dfs(child, word, index + 1))
                    return true;
            }
            return false;
        }
        return dfs(node->children[c - 'a'], word, index + 1);
    }

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode* node = root;
        for (const auto& c: word)
        {
            if (node->children[c - 'a'] == nullptr)
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

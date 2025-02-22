//
// Created by Ruohao L. on 21/02/2025.
//
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet
{
private:
    unordered_map<int, size_t> pos_map; // 存储接下来vector中的<值->索引>的映射
    vector<int> vals; // 存储所有的值
public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (pos_map.count(val)) return false; // val 已经存在，按题意返回 false
        vals.push_back(val);
        pos_map[val] = vals.size() - 1; // 记录 val 的索引
        return true;
    }

    bool remove(int val)
    {
        if (!pos_map.count(val)) return false; // val 不存在，按题意返回 false

        // 1. 获取 val 的索引
        size_t index = pos_map[val];

        // 2. 交换被删除元素和最后一个元素
        int lastVal = vals.back(); // & [last]，然后 int lastVal = ... 这里发生了拷贝，所以 lastVal 变成了一个普通的 int，存的是 & [last] 的值
        vals[index] = lastVal; // 相当于val已经被覆盖从而消失了
        pos_map[lastVal] = index; //lastVal还要继续存在，且准备存在在index这里

        // 3. 删除最后一个元素（避免 O(n) 的删除）
        vals.pop_back();
        pos_map.erase(val);

        return true;
    }

    int getRandom()
    {
        // 取 rand() 生成的随机数对 vals.size() 取模，保证最终结果在 [0, vals.size() - 1] 之间，也就是 vals 这个 vector 的合法索引范围
        return vals[rand() % vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

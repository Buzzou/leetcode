//
// Created by Ruohao L. on 27/02/2025.
//
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache
{
private:
    int capacity;
    unordered_map<int, list<pair<int, int> >::iterator> map; // key -> 对应的双向链表迭代器：所以之后不用循环链表找 key
    list<pair<int, int> > cache; // 双向链表 (key, value)

public:
    LRUCache(int capacity): capacity(capacity) {}

    int get(int key)
    {
        if (map.find(key) == map.end()) return -1; // key 不存在
        // key 存在，移动到表头（最近使用）
        cache.splice(cache.begin(), cache, map[key]); // O(1) 移动到头部
        return map[key]->second; // 返回 value
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            // key 已存在，更新 value，并移动到表头
            cache.splice(cache.begin(), cache, map[key]); // O(1) 移动到头部
            map[key]->second = value; // 更新 value
        }
        else
        {
            // key 不存在，需要插入
            if (cache.size() >= capacity)
            {
                // 超过容量，删除 LRU (链表尾部元素)
                map.erase(cache.back().first);
                cache.pop_back(); // O(1) 删除 LRU
            }
            // 插入新元素到表头
            cache.emplace_front(key, value); // emplace_front 可以直接构造 std::pair
            map[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache cache(2);

    cache.put(1, 1); // cache = {1=1}
    cache.put(2, 2); // cache = {1=1, 2=2}

    std::cout << cache.get(1) << std::endl; // 返回 1，cache = {2=2, 1=1}

    cache.put(3, 3); // LRU 是 2，删除 2，cache = {1=1, 3=3}

    std::cout << cache.get(2) << std::endl; // 返回 -1 (不存在)

    cache.put(4, 4); // LRU 是 1，删除 1，cache = {3=3, 4=4}

    std::cout << cache.get(1) << std::endl; // 返回 -1 (不存在)
    std::cout << cache.get(3) << std::endl; // 返回 3
    std::cout << cache.get(4) << std::endl; // 返回 4

    return 0;
}

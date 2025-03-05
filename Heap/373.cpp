//
// Created by Ruohao L. on 05/03/2025.
//
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<vector<int> > result;
        if (nums1.size() == 0 || nums2.size() == 0 || 0 == k) return result;

        // Min heap: stores (sum, i, j), sorted by sum (default priority_queue is max-heap)
        // 当 a 的<0>大于 b 的<0>时，a 应该排在「后」面，从而使得堆顶（即第一个被取出的元素）总是具有最小和的那个对
        auto cmp = [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<0>(a) > get<0>(b); // Min-heap based on sum
        };
        // 使用 decltype(cmp) 可以自动推导这个 lambda 的类型，并用作 priority_queue 模板参数中的比较器类型，简化模板参数的写法
        // 这样写的好处是不用手动指定比较器的类型，因为 lambda 类型通常比较复杂且匿名。
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, decltype(cmp)> minHeap(cmp);

        // Initialize the heap with the smallest pairs (nums1[i], nums2[0])
        for (int i = 0; i < min(static_cast<int>(nums1.size()), k); ++i) minHeap.emplace(nums1[i] + nums2[0], i, 0);

        // Extract k smallest pairs
        while (k-- > 0 && !minHeap.empty())
        {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});

            // If there is a next element in nums2, push (nums1[i], nums2[j+1]) into heap
            if (j + 1 < nums2.size()) minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
        }

        return result;
    }
};

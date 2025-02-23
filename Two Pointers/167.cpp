//
// Created by Ruohao L. on 23/02/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        unsigned short left = 0, right = numbers.size() - 1; // 2 <= numbers.length <= 3 * 10^4
        while (left < right)
        {
            short sum = numbers[left] + numbers[right]; // -1000 <= numbers[i] <= 1000
            if (sum == target)
            {
                return {left + 1, right + 1}; // 1-indexed 返回
            }
            else if (sum < target) ++left; // 需要更大的数
            else --right; // 需要更小的数
        }
        return {}; // 题目保证有解，所以不会执行到这里
    }
};

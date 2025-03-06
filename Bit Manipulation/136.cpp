//
// Created by Ruohao L. on 06/03/2025.
//
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};

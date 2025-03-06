//
// Created by Ruohao L. on 05/03/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int res = 0;
        for (const int num: nums) res ^= num;
        return res;
    }
};

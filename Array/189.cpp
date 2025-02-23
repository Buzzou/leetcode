//
// Created by Ruohao L. on 20/02/2025.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution
{
public:
    static void rotate(vector<int>& nums, int k)
    {
        if (nums.size() == 1) { ; }
        else if (0 == k || 0 == k % nums.size()) { ; }
        else if (nums.size() - k < 0)
        {
            k %= nums.size();
            std::rotate(nums.begin(), nums.end() - k, nums.end());
        }
        else
            std::rotate(nums.begin(), nums.end() - k, nums.end());
    }
};

int main()
{
    vector<int> nums={1,2};
    short k=3;
    copy(nums.begin(),nums.end(),ostream_iterator<int>(cout," "));
}

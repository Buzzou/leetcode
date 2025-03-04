//
// Created by Ruohao L. on 04/03/2025.
//
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    static vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > result;
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);

        vector<int> temp(k);

        do
        {
            copy(nums.begin(), nums.begin() + k, temp.begin());
            result.push_back(temp);
        }
        while (ranges::next_permutation(nums.begin(), nums.begin() + k, nums.end()));
    }
};

int main()
{
    int n=4, k=2;
    Solution::combine(n,k);
}

//
// Created by Ruohao L. on 19/02/2025.
//
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    static int removeElement(vector<int>& nums, int val)
    {
        erase(nums, nums.end());
        // copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
        // cout << endl;

        return nums.size();
    }
};

int main()
{
    vector<int> nums1 = {3,2,2,3};
    char val1 = 3;
    cout << Solution::removeElement(nums1, val1) << endl;

    vector<int> nums2 = {0,1,2,2,3,0,4,2};
    char val2 = 2;
    cout << Solution::removeElement(nums2, val2) << endl;
}

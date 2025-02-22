//
// Created by Ruohao L. on 19/02/2025.
//
#include <iostream>
#include <ostream>
#include <vector>
#include <__algorithm/ranges_unique.h>
using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        auto new_end = unique(nums.begin(), nums.end());

        return new_end - nums.begin();
    }
};

int main()
{
    vector<int> nums1{1,1,2};
    cout << Solution::removeDuplicates(nums1) << endl;

    vector<int> nums2{0,0,1,1,1,2,2,3,3,4};
    cout << Solution::removeDuplicates(nums2) << endl;
}

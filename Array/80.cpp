//
// Created by Ruohao L. on 19/02/2025.
//
#include <vector>
#include <__algorithm/ranges_unique.h>
#include <iostream>
#include <iterator>
using namespace std;

class Solution
{
public:
    static int removeDuplicates(vector<int>& nums)
    {
        size_t count = 0;
        auto new_end = unique(nums.begin(), nums.end(), [&count](int a, int b) {
            if (a == b) ++count;
            else count = 0;
            return count >= 2;
        });
        copy(nums.begin(), new_end, ostream_iterator<int>(cout, " "));
        cout << endl;

        nums.erase(new_end, nums.end());
        copy(nums.begin(), new_end, ostream_iterator<int>(cout, " "));
        cout << endl;

        return new_end - nums.begin();
    }
};

int main()
{
    vector<int> nums1{1, 1, 1, 2, 2, 3};
    cout << Solution::removeDuplicates(nums1) << endl;

    vector<int> nums2{0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << Solution::removeDuplicates(nums2) << endl;
}

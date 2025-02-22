//
// Created by Ruohao L. on 19/02/2025.
//
//
// Created by Ruohao L. on 19/02/2025.
//
#include <vector>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <iterator>
using namespace std;

class Solution
{
public:
    static vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        /**
         *@param m 是 nums1 的非零元素个数
         *@param n 是 nums2 的元素个数
         */
        nums1.erase(nums1.begin()+m, nums1.end());
        // copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout, " "));
        // cout << endl;

        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        // copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout, " "));
        // cout << endl;

        sort(nums1.begin(), nums1.end());

        return nums1;
    }
};

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0};
    unsigned char m1 = 3;
    vector<int> nums2 = {2,5,6};
    unsigned char n2 = 3;
    assert(n2 == 3);
    vector<int> temp1 = std::move(Solution::merge(nums1,m1,nums2,n2));

    copy(temp1.begin(), temp1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "test 1 terminates" << endl;

    vector<int> nums3 = {1};
    unsigned char m3 = 1;
    vector<int> nums4;
    unsigned char n4 = 0;
    assert(n4 == 0);
    vector<int> temp2 = std::move(Solution::merge(nums3,m3,nums4,n4));

    copy(temp2.begin(), temp2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "test 2 terminates" << endl;

    vector<int> nums5 = {0};
    unsigned char m5 = 0;
    vector<int> nums6 = {1};
    unsigned char n6 = 1;
    assert(n6 == 1);
    vector<int> temp3 = std::move(Solution::merge(nums5,m5,nums6,n6));

    copy(temp3.begin(), temp3.end(), ostream_iterator<int>(cout, " "));cout << endl;
    cout << "test 3 terminates" << endl;
}

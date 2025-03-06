//
// Created by Ruohao L. on 06/03/2025.
//
#include <bitset>
using namespace std;

class Solution
{
public:
    int hammingWeight(int n)
    {
        bitset<32> bs(n);
        return bs.count();
    }
};

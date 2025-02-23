//
// Created by Ruohao L. on 21/02/2025.
//
#include <vector>
#include <__algorithm/ranges_sort.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] < i + 1) return i;
        }
        return citations.size();
    }
};

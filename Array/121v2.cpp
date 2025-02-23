//
// Created by Ruohao L. on 20/02/2025.
//
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    static int maxProfit(vector<int>& prices)
    {
        if (is_sorted(prices.begin(), prices.end(), greater_equal<int>()))
            return 0;
        int maxProf = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            maxProf = max(maxProf, prices[i] - minPrice);

            minPrice = min(minPrice, prices[i]);
        }
        return maxProf;
    }
};

int main()
{

}

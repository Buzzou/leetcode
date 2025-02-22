//
// Created by Ruohao L. on 20/02/2025.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (is_sorted(prices.begin(), prices.end(), greater_equal<int>()))
            return 0;
        else if (is_sorted(prices.begin(), prices.end()))
            return (*(prices.end() - 1) - *prices.begin());
        else
        {
            size_t profit = 0;
            for (unsigned short i = 1; i < prices.size(); ++i)
            {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }
    }
};

//
// Created by Ruohao L. on 20/02/2025.
// 这个方法的问题在于找到全局最小值后才寻找最大值，但这样会导致 min_iter 可能落在数组末尾，使 max_element 失效，比如 [2,4,1]
//
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    static int maxProfit(vector<int>& prices)
    {
        if (is_sorted(prices.begin(), prices.end(), greater_equal<int>()))
            return 0;
        else
        {
            auto min_index = min_element(prices.begin(), prices.end());
            cout << *min_index << endl;
            auto local_max_index = max_element(min_index, prices.end());
            cout << *local_max_index << endl;

            return *local_max_index - *min_index;
        }
    }
};

int main()
{
    vector<int> prices{2,4,1};
    cout << Solution::maxProfit(prices) << endl;
}

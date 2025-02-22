//
// Created by Ruohao L. on 21/02/2025.
//
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        vector<unsigned int> candies(ratings.size(), 1); // 每个孩子至少 1 颗糖

        // **左到右遍历**: 确保右边评分更高的孩子拿到更多的糖
        for (unsigned short i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
        }

        // **右到左遍历**: 确保左边评分更低但糖果不够的情况
        for (short i=ratings.size()-2; i>=0; --i)
        {
            if (ratings[i] > ratings[i+1]) candies[i] = max(candies[i],candies[i+1] + 1);
            // if (ratings[i] > ratings[i+1]) candies[i] = candies[i+1] + 1;
        }

        // 计算糖果总数
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

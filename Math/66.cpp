//
// Created by Ruohao L. on 05/03/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0; // 当前位变 0，进位到前一位
        }
        // 如果循环真的结束了，说明所有位都是 9，需要在前面加 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

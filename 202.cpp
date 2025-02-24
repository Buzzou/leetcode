//
// Created by Ruohao L. on 24/02/2025.
//
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<unsigned int> seen; // 记录出现过的数
        while (n != 1 && !seen.count(n))
        {
            seen.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }

private:
    unsigned int getNext(int n)
    {
        unsigned int sum = 0;
        while (n > 0)
        {
            char digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};

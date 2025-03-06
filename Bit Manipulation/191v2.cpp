//
// Created by Ruohao L. on 05/03/2025.
//
class Solution
{
public:
    int hammingWeight(int n)
    {
        char count = 0;
        while (n)
        {
            count++;
            n &= (n - 1);
        }
        return count;
    }
};

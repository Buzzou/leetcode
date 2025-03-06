//
// Created by Ruohao L. on 05/03/2025.
//
class Solution
{
public:
    double myPow(double x, int n)
    {
        long n_ = n;// n == -2147483648 则 -n 不能被 int 所表示

        if (n_ < 0)
        {
            x = 1 / x;
            n_ = -n_;
        }

        double result = 1;
        while (n_ > 0)
        {
            if (n_ % 2 == 1) result *= x; // 如果是奇数，多乘一个 x
            x *= x; // x 平方
            n_ >>= 1; // n 变成一半
        }
        return result;
    }
};

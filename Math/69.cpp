//
// Created by Ruohao L. on 05/03/2025.
//
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0) return 0; // 特例

        int left = 1, right = x, ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid * mid == x) return mid; // 找到精确平方根
            if (mid * mid < x)
            {
                ans = mid; // mid 可能是答案
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};

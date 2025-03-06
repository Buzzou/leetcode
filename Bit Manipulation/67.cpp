//
// Created by Ruohao L. on 05/03/2025.
//
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        short i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string result;

        while (i >= 0 || j >= 0 || carry)
        {
            char sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            // 通过 (sum % 2) + '0' 的操作，可以利用字符 '0' 的 ASCII 值（48）来转换整数为相应的数字字符
            // 例如，0 + '0' 得到 '0'，1 + '0' 得到 '1'。
            result.push_back(sum % 2 + '0');
            carry = sum / 2;
        }

        // 因为我们是从最低位开始添加，所以最后需要反转结果字符串
        reverse(result.begin(), result.end());
        return result;
    }
};

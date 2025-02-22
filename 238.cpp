//
// Created by Ruohao L. on 21/02/2025.
//
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        unsigned int length = nums.size();
        vector<int> answer(length,1);// 初始化答案数组

        // 计算左侧乘积 L[i]
        int leftProduct = 1;//1代表左边没有数，取1是因为方便接下来任何数乘1都等于任何数
        for (unsigned int i = 0; i < length; ++i)
        {
            answer[i] = leftProduct;
            leftProduct *= nums[i];// 更新左乘积
        }

        // 计算右侧乘积 R[i] 并直接更新 answer[i]
        int rightProduct = 1;
        for (int i = length-1; i >= 0; --i)
        {
            answer[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return answer;
    }
};

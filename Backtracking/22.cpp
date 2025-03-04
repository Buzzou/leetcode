//
// Created by Ruohao L. on 04/03/2025.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string path, char left, char right, char n)
    {
        if (path.size() == n * 2)
        // 终止条件：合法序列
        {
            result.push_back(path);
            return;
        }

        if (left < n) backtrack(result, path + "(", left + 1, right, n); // 还能加左括号
        if (right < left) backtrack(result, path + ")", left, right + 1, n); // 右括号数量不能超过左括号
    }
};

int main()
{
    Solution sol;
    vector<string> res = sol.generateParenthesis(3);
    for (const string& s: res)
    {
        cout << s << endl;
    }
}

/*不能只用回溯枚举所有可能的括号序列，否则会出现大量无效的括号组合。
不过，你不需要额外用栈来判断括号是否匹配，而是在递归的过程中直接保证括号的合法性。
不能超过 n 对括号：
只能放 n 个左括号 (。
只能放 n 个右括号 )。
必须保证 ) 的数量不超过 (：
只有 left > right 时，才可以放 )，否则就变成了无效括号序列。
递归树解析（n = 3）
                ""
             /       \
           (          X  (不可能先加 ')') -- left < n → 加 (，调用 backtrack("(", 1, 0, 3)
         /   \
      ((      ()                        -- left < n → 加 (，调用 backtrack("((", 2, 0, 3)
     /   \      \                       ⤴ ((( 期待的第二个 if 的 return 了，所以 ((( 得以执行完第二个 if，返回上层；而上层还没来得及执行第二个 if
  (((     (()    ()(                    -- left < n → 加 (，调用 backtrack("(((", 3, 0, 3)
    |     /   \     \                   ⤴ ))) 返回 return 给 )) -> 给 ) -> 给 ((( 期待的 第二个 if 的执行结果
  ((())) (())() ()(())                  -- 不能再加 (，right < left → 加 )，调用 backtrack("((()", 3, 1·2·3, 3)
          |       |
       (()())   ()()()
最终结果：
["((()))","(()())","(())()","()(())","()()()"]
每次递归都保证了 左括号 >= 右括号，不会生成非法序列。
复杂度分析
时间复杂度：O(4^n / sqrt(n))（卡特兰数）
空间复杂度：O(n)（递归深度）*/

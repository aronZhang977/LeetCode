/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i = 0;
        for(int num : pushed)
        {
            stk.push(num);
            // 这两个顺序不能颠倒  && 的结合律 是先左
            while(!stk.empty() && stk.top() == popped[i])
            {
                stk.pop();
                ++i;
            }
        }

        return stk.empty();
    
    }
};
// @lc code=end


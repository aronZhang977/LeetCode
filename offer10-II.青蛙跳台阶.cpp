/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：2
示例 2：

输入：n = 7
输出：21
示例 3：

输入：n = 0
输出：1

注意：本题与主站 70 题相同：https://leetcode-cn.com/problems/climbing-stairs/
*/


//  经典动态规划问题，需要注意的是取模 
class Solution {
public:
    int numWays(int n) {
        int p = 0, q = 0, r = 1;
        for(int i = 0; i < n; ++i)
        {
            q = p;
            p = r;
            r = (p + q) % 1000000007;
        }
        return r;
    }
};
/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */

// @lc code=start
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n,vector<int>(n)); //  n*n 矩阵
        dp[0][0] = true;
       //当第i个石子与第 i−1 个石子距离超过 i 时，青蛙必定无法到达
        for(int i = 1; i != n; ++i)
        {
            if(stones[i] - stones[i - 1] > i)
            {
                return false;
            }
        }
        // i 是这一跳的位置
        for(int i = 1; i < n; ++i)
        {
            for(int j = i - 1; j >= 0; --j)
            {
                int k = stones[i] - stones[j];
                if(k > j + 1)
                {
                    break;
                }
                // j是上一跳位置 k是上一跳步长
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                // 最后一块石头 这一行有1 即代表能上岸
                if (i == n - 1 && dp[i][k])
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end


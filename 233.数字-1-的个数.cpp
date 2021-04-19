/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start

// 数学方法
class Solution {
public:
    int countDigitOne(int n) {
        int ncount = 0;
        for(long long i = 1; i <= n; i *= 10)
        {
            long long divider = i * 10;
            ncount += (n / divider) * i + min(max(n % divider - i + 1,0LL),i);
        }
        return ncount;
    }
};

// @lc code=end


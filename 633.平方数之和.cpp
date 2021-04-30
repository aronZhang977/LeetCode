/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start

// sqrt 函数 
class Solution {
public:
    bool judgeSquareSum(int c) {
        //使用 long 避免溢出 
        //或者  a < (int)Math.sqrt(c)
        for(long a = 0; a * a <= c; ++a)
        {
            double b = sqrt(c - a * a);
            if(b == (int)b)
                return true;
        }
        return false;
    }
};

// 双指针
class Solution{
public:
    bool judgeSquareSum(int c)
    {
        long left = 0;
        long right = (int)sqrt(c);

        while(left <= right)
        {
            long sum = left * left + right * right;
            if (sum == c)
                return true;
            else if(sum > c)
                --right;
            else 
                ++left;
        }
        return false;
    }
};

// @lc code=end


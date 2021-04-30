/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start

// 数字电路  使一个数 计算三次以后归零

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num: nums) {
            b = ~a & (b ^ num);
            a = ~b & (a ^ num);
        }
        return b;
    }
};


// 依次确定二进制位
class Solution{
public:
    int singleNumber(vector<int>& nums)
    {
        int res = 0;
        // int  32位整数 
        // 答案的第 ii 个二进制位就是数组中所有元素的第 ii 个二进制位之和除以 33 的余数
        for(int i = 0; i < 32; ++i)
        {
            int total = 0;
            for(int n : nums)
            {
                total += ((n >> i) & 0x1);
            }
            if(total %3)
            {
                res |= (0x1 << i);
            }
        }
        return res;
    }
};

// 使用unordered_map统计出现次数  然后遍历unordered_map得到目标值
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;

        for(auto n : nums)
        {
            ++map[n];
        }

        int res = 0;
        for(auto [n,count] : map)
        {
            if(1 == count)
            {
                res = n;
                break;
            }
        }
        return res;
    }
};
// @lc code=end


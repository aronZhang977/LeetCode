/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
// 利用异或运算  a^a = 0  0^b = b 的特性
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int n : nums)
        {
            res ^= n;
        }
        return res;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto n :nums)
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


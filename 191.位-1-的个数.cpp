/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for(int i = 0; i < 32; ++i)
        {
            // 通过把1 位移到检查位置，再与原数 & 运算来检查该位置是否为1
            if(n & (1 << i))
            {
                ++ret;    
            }
        }
    return ret;
    }  
};
// @lc code=end


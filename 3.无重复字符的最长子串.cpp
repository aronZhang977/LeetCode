<<<<<<< HEAD
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n = s.size();
        int rk = -1, ans = 0;
        for(int i = 0;i < n;++i)
        {
            if(i != 0)
                occ.erase(s[i - 1]);
                //如果不能添加rk+1所指向的元素，count会返回1，否则返回0
            while(rk + 1 < n&& !occ.count(s[rk + 1]))
            {
                occ.insert(s[rk + 1]);
                ++rk;
            }    
            ans = max(ans,rk - i + 1);
        }
        return ans;
    }
};
// @lc code=end

=======
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    

    }
};
// @lc code=end

>>>>>>> 205afd2 (0330)

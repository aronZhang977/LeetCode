/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
private:
    unordered_map<char,int> symbolValues =  {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
public:
    //要对比下一个字符的大小是不是比当前的大
    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();
        for(int i = 0; i < n; ++i)
        {
            int value = symbolValues[s[i]];
            // 利用 && 短路确保i+1能取到值
            if(i < n - 1 && value < symbolValues[s[i + 1]])
            {
                ans -= value;
            }
            else
            {
                ans += value;
            }
        }
        return ans;
    }
};
// @lc code=end


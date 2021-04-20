/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。
 * 
 * 在一个串里找另一个串出现的第一个位置。
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        for(int i = 0; i + len2 <= len1 ; ++i)
        {
            bool flag = true;
            for(int j = 0; j != len2; ++j)
            {
                if(haystack[i + j] != needle[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                return i;
        }
        return -1;
    }
};
// @lc code=end


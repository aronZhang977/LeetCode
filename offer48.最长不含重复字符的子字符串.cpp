
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合用来记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针初始值为-1，相当于字符串的左边界的左侧
        int rk = -1,ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为-1
        for(int i = 0; i != n;++i)
        {
            if(i != 0)
            {
                // 左指针想右移动一格，移除一格字符
                occ.erase(s[i - 1]);
            }
            while(rk + 1 != n && !occ.count(s[rk + 1]))
            {
                //不断移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第i到rk个字符是一个极长的无重复字符子串
            ans = max(ans,rk - i +1);
        }
        return ans;        
    }
};
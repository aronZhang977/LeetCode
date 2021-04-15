// 输入一个字符串，打印出该字符串中字符的所有排列。
class Solution {
public:
    vector<string> permutation(string s) {
        dfs(s,0);
        return res;
    }
private:
    vector<string> res;
    void dfs(string str, int x)
    {
        if( x == str.size() - 1)
        {
            res.push_back(str);   //添加排列方案
            return;
        }
        set<int> set;               // 用set来查重
        for(int i = x; i < s.size(); ++i)
        {
            if(set.find(str[i]) != set.end())
                continue;                   // 重复， 剪枝
            set.insert(str[i]);
            swap(str[i],str[x]);        // 交换，将s[i]固定在第x位
            dfs(str,x + 1);             // 开启固定第x+1位字符
            swap(str[i],str[x]);        // 恢复交换
        }
    }
};
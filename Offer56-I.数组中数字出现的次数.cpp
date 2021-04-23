// 分组异或
class Solution{
public:
    vector<int> singleNumbers(vector<int>& nums){
        int ret = 0;
        // 遍历遍历一遍，得到的ret是两个出现一次的值 a^b
        for(int n : nums)
            ret ^= n;
        // 找a^b 的 二进制值为1的位置
        int div = 1;
        while (!(div & ret))
            div <<=1;
        int a = 0,b = 0;
        // 利用div对原来的数组进行分组 并且分别再异或一遍这样得到的a,b即为所求
        for(int n : nums)
        {
            if(div & n)
                a ^= n;
            else
                b ^= n;
        }
        return vector<int>{a,b};
    }
};


// 用一个set来辅助
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        set<int> set;
        for(int& n : nums)
        {
            auto it = set.find(n);
            if(set.end() == it)
            {
                set.insert(n);
            }
            else
            {
                set.erase(it);
            }
        }
#if 0
        for(int i = 0; i != nums.size(); ++i)
        {
            auto it = set.find(nums[i]);
            if(set.end() == it)
            {
                set.insert(nums[i]);
            }
            else
            {
                set.erase(it);     
            }
        }
#endif
        vector<int> res;
        res.assign(set.begin(),set.end());
        return res;
    }
};
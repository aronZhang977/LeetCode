// 暴力  转成字符串  用count统计
class Solution {
public:
    int countDigitOne(int n) {
        int ncount = 0;
        for(int i = 0; i <= n; ++i)
        {
            string str = to_string(i);
            ncount += count(str.begin(),str.end(),'1');
        }
        return ncount;
    }
};

// 数学方法
class Solution {
public:
    int countDigitOne(int n) {
        int ncount = 0;
        for(long long i = 1; i <= n; i *= 10)
        {
            long long divider = i * 10;
            ncount += (n / divider) * i + min(max(n % divider - i + 1,0LL),i);
        }
        return ncount;
    }
};

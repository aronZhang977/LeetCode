
// 双指针 暴力遍历
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),res = 0;
        for(int i = 0; i < n;++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                res = max(res,prices[j] - prices[i]);
            }
        }
        return res;
    }
};


// 一次遍历
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX,maxprofit = 0;
        for(int price : prices)
        {
            maxprofit = max(maxprofit,price - minprice);
            minprice = min(price,minprice);
        }
        return maxprofit;
    }
};
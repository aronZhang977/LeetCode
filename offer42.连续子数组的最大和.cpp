
// 暴力搜索
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

    }
};

// 分治思想  线段树
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

    }
};

// 动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for(const auto &x:nums)
        {
            pre = max(pre + x,x);
            maxAns = max(maxAns,pre);
        }
        return maxAns;
    }
};
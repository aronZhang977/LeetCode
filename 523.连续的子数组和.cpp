/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int  m = nums.size();
        if(m < 2)
            return false;
        unordered_map<int,int> map;
        map[0] = -1;
        int remainder = 0;
        for(int i = 0; i < m; i++)
        {
            remainder = (remainder + nums[i]) % k;
            if( map.count(remainder))
            {
                int preIndex = map[remainder];
                if(i - preIndex >= 2)
                {
                    return true;
                }
            }
            else
            {
                map[remainder] = i;
            }
        }
        return false;
    }
};


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> set;  // 用set存前缀和
        int sum = 0;
        int pre = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            int temp = sum % k;
            if(set.count(temp))
                return true;
            set.insert(pre);
            pre = temp;
        }
        return false;
    }
}；

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

    }
};
// @lc code=end


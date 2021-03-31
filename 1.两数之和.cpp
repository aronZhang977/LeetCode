/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
    // 哈希表
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int,int> hashtable;
        for(int i = 0; i != len ; ++i)
        {
            auto it = hashtable.find(target - nums[i]);
            if(it != hashtable.end())
            {
                return {it->second,i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
/*
以[2,7,11,15]为例
hashtable
| | |0| | | | |
 0 1 2 
 循环内 i = 7 时  命中
 返回  {0,1}
*/
// @lc code=end


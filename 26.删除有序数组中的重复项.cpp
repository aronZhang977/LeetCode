/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
// 双指针
class Solution {
public:

    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
        {
            return 0;
        }
        int fast = 1, slow = 1;
        while(fast < len)
        {
            if(nums[fast] != nums[fast - 1])
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

// 用erase
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 2)
            return len;
        auto it = nums.begin();
    
        for(int i = 0; i < nums.size() - 1;)
        {
            if(nums[i] == nums[i + 1])
            {
                it = nums.erase(it + 1);
            }
            else{
                it++;
                i++;
            }
        } 
        return nums.size();
    }
};
// @lc code=end


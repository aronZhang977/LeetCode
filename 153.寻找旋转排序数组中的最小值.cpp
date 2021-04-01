/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = left  + (right - left) / 2;   //  把 (left+right)/2 写成这个形式防止溢出
            if(nums[mid] > nums[right])
            {
                left = mid + 1; // 因为中值 > 右值，中值肯定不是最小值，左边界可以跨过mid
            }else if (nums[mid] < nums[right]) 
            {
                right = mid;
            }
        }
        return nums[right];
    }
};
// @lc code=end


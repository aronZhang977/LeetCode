/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            // 大于小于等于分开处理
            int mid = left - (left - right) / 2;
            if (nums[mid] > nums[right] )
            {
                left = mid + 1;
            }
            else if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else
            {
                --right;
            }
        }
        return nums[left];
    }
};
// @lc code=end


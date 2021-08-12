/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start

class Solution {
public:
    // 不停的找有序的一边对比直到mid == target 或者 left right相交
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        int left = 0, right = end, mid = 0;
        if (right == -1)
            return -1;
        if(right == 0)
            return nums[right] == target ? right : -1;

        while (left <= right)
        {
            mid = (right - left) / 2 + left;
            if (nums[mid] == target)
                return mid;
            if (nums[begin] <= nums[mid])
            {
                if (nums[begin] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if (nums[begin] >= nums[mid])
            {
                if (nums[mid] < target && target <= nums[end])
                    left = mid + 1;
                else 
                    right = mid -1;
            }
        }
        return -1;
    }
};
// @lc code=end


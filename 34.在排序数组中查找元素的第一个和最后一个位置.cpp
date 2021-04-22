/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start

//二分查找 更直观的版本
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty() || *nums.begin()>target || *nums.rbegin()<target)
            return {-1,-1}; 
        int left=left_qsort(nums,target);
        int right=right_qsort(nums,target);
        return {left,right};
    }
    int left_qsort(vector<int>& nums,int target){
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return nums[l]==target ? l:-1;
    }
    int right_qsort(vector<int>& nums,int target){
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<=target)
                l=mid+1;
            else
                r=mid-1;
        }
        return nums[r]==target ? r:-1;
    }

};


class Solution {
public:
    int binarySearch(vector<int>& nums, int target,bool lower)
    {
        int left = 0, right = nums.size - 1, ans = nums.size();
        while (left <= right)
        {
            int mid = (left + right) /2; // right-(right - left) /2
            if(nums[mid] > target || (lower && nums[mid] >= target))
            {
                right = mid - 1;
                ans = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = binarySearch(nums,target,true);
        int rightIndex = binarySearch(nums,target,false) - 1;
        if(leftIndex <= rightIndex && rightIndex < nums.size() 
            && nums[leftIndex] == target && nums[rightIndex] == target)
            {
                return vector<int> {leftIndex,rightIndex};
            }
        return vector<int>{-1,-1};
    }
};
// @lc code=end


class Solution {
public:
    // 二分查找
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return 0;
        int l_boundary, r_boundary;
        int left = 0, right = len-1;
        //查找右边界
        while(left <= right){
            int mid = (left + right) >> 1;
            if(nums[mid] <= target){
                left = mid + 1;
            }else{
                right = mid -1;
            }
        }
        r_boundary = left;
        if(right<0 || nums[right]!=target) return 0;
        right = left;
        left = 0;
        //查找左边界
        while(left <= right){
            int mid = (left + right) >> 1;
            if(nums[mid] >= target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        l_boundary = right;
        return r_boundary - l_boundary -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
    //暴力遍历 
    int times = 0;
        for(int i=0;i<nums.size();i++)
            if(nums[i] == target) times++;
        return times;
    }
};

// 哈希
class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int num : nums){
            ++map[num];
        }
        return map[target];
    }
};

 

// stl
class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto iter = lower_bound(nums.begin(), nums.end(), target);  //寻找下边界
        auto iter2 = upper_bound(nums.begin(), nums.end(), target); //寻找上边界
        return iter2 - iter;    // [iter,iter2) 左闭右开区间 
    }
};
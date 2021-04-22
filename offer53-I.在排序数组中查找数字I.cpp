

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
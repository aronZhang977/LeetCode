/*
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 

*/

// unordered_set
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> hashset;
        int count = 0; 
        for(int i = 0;i < nums.size(); ++i)
        {
            count = hashset.size();
            hashset.insert(nums[i]);
            if(count + 1 != hashset.size())
            {
                return nums[i];   
            }            
        }
        return -1;
    }
};

// unordered_map
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,bool> hashmap;

        for(int i:nums)
        {
            if(hashmap[i])
                return nums[i];
            hashmap[i] = true;
        }
        return -1;
    }
};

// 上边unordered_map的内存消耗反而比unordered_set小。为啥了



// 原地置换法
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i != nums.size(); ++i)
        {
            while (nums[nums[i]] != nums[i])
                swap(nums[nums[i]],nums[i]);
            if(nums[i] != i)
                return nums[i];        
        }
        return -1;
    }
};


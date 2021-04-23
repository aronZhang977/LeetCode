// 双指针 
class Solution{
public:
    vector<int> twoSum(vector<int>& nums,int target)
    {
        int left = 0, right = nums.size() - 1;

        while(left < right)
        {
            if(nums[left] + nums[right] > target)
            {
                --right;
            }
            else if(nums[left] + nums[right] < target)
            {
                ++left;
            }
            else
            {
                return vector<int> {nums[left],nums[right]};
            }
        }
        return {};
    }
};
// 哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;   // 值，位置

        for(int i = 0; i != nums.size(); ++i)
        {
            auto it = map.find(target - nums[i]);
            if(it != map.end())
                return vector<int>{it->second, i};
            map[nums[i]] = i;
        }
        return {};
    }
};
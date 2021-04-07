// 首尾指针 原地交换
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while(left < right)
        {
            if (nums[left] & 0x1)
            {
                ++left;
                continue;
            }
            else if(!(nums[right] & 0x1))
            {
                --right;
                continue;
            }
            std::swap(nums[left++],nums[right--]);   
        }
        return nums;
  }
};
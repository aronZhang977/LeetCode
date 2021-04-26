// 哈希
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        vector<int> map(14);   // 用数组构建哈希集合
        int minVale = INT_MAX, maxValue = INT_MIN;
        for(int n : nums)
        {
            if(map[n] >= 1)
                return false;   // 重复数字
            if(0 == n)
                continue;       // 大小王、跳过
            minVale = min(minVale,n);
            maxValue = max(maxValue,n);
            ++map[n];
        }
        return maxValue - minVale <= 4;
    }
};

// 排序
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int minIndex = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            if(0 == nums[i])
                ++minIndex;
            else if(nums[i] == nums[i + 1])
                return false;
        }
        return nums[4] - nums[minIndex] <= 4;

    }
};

// 方法1 ： 用unordered_map <num, count>存一遍数据
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        for (int n : nums)
        {
            if(++map[n] > nums.size()/2) // 这个地方加计数
                return n;
        }
        return -1;
    }
};

// 方法2 排序，因为出现频率大于n/2，所以排序后的中间位置必然是他
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];          //因为出现频率大于n/2，所以排序后的中间位置必然是众数
    }
};

// 方法3：摩尔投票  同则叠加  不同则抵消  最后过半的必然是所求
class Solution {
public:
    int majorityElement(vector<int>& nums) {    
        int candidate = 0,votes = 0;  // 候选人和票数  票数为0 时  换候选人
        for(int n : nums)
        {
            if(!votes)
                candidate = n;
            (n == candidate) ? ++votes:--votes;
        }
        return candidate;
    }
};


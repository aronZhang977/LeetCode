/*输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
*/


// 暴力枚举
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> vec;
        
        for(int i = 1; i <= (target - 1) / 2; ++i)
        {
            int sum = 0;
            for(int j = i; ;++j)
            {
                sum += j;
                if(sum > target)
                {
                    //过界
                    break;
                }
                else if(sum == target)
                {
                    vec.clear();
                    for(int k = i;k <= j; ++k)
                    {
                        vec.emplace_back(k);
                    }
                    res.emplace_back(vec);
                    break;
                }
            }            
        }
        return res;
    }
};


// 双指针   对暴力枚举的优化
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> vec;
        int left = 1,right = 2;
        while (left < right)
        {
            int sum = (left + right) * (right - left + 1) / 2;
            if(sum == target)
            {
                vec.clear();
                for(int i = left; i <= right; ++i)
                {
                    vec.emplace_back(i);
                }
                res.emplace_back(vec);
                ++left;
            }
            else if(sum < target)
            {
                ++right;
            }
            else{
                ++left;
            }
        }
        return res;
    }
};
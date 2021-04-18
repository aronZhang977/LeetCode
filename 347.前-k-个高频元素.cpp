/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
/*
    1.遍历整个数组，并使用哈希表记录每个数字出现的次数
    2.堆排 c++的priority_queue大顶堆  顶上是最小里最大的元素，正好用来比较
*/
    static bool cmp(pair<int,int>& m, pair<int,int>& n)
    {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;   // nums , count
        for(auto& i : nums)
        {
            ++map[i];
        }
        /*
        for(int i = 0; i < nums.size();++i)
        {
            ++map[nums[i]];
        }
        */
        /*
         * 定义：priority_queue<Type, Container, Functional>
         * Type 就是数据类型，
         * Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector），
         * Functional 就是比较的方式。当需要用自定义的数据类型时才需要传入这三个参数，使用基本数据类型时，只需要传入数据类型，默认是大顶堆。
        */
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> que(cmp);
        for(auto& [num,count] : map)
        {
            // k个以后
            if(que.size() == k)
            {
                if(que.top().second < count)
                {
                    que.pop();
                    que.emplace(num,count);
                }
            }else{
                // 前k个
                que.emplace(num,count);
            }
        }
        vector<int> res;
        while(!que.empty())
        {
            res.emplace_back(que.top().first);
            que.pop();
        }
        return res;
    }
};
// @lc code=end


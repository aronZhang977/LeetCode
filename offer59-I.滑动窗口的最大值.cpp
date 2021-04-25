
// 优先队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> que;  // 值，位置

        for(int i = 0; i < k; ++i)
        {
            que.emplace(nums[i],i);
        }
        vector<int> res = {que.top().first};
        for(int i = k; i < n; ++i)
        {
            que.emplace(nums[i],i);
            // 找到当前位置下的最大值 进入数组
            while ((que.top().second <= i - k))
            {
                que.pop();
            }
            res.push_back(que.top().first);            
        }
        return res;
    }
};

//单调队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(!n)
            return {};
        deque<int> que; // 双端队列 存元素位置 后边存 前边出
        // 先入k-1个中的最大值
        for(int i = 0; i < k; ++i)
        {
            while(!que.empty() && nums[i] >= nums[que.back()])
            {
                que.pop_back();
            }
            que.push_back(i);
        }
        // 开始窗口移动
        vector<int> res = {nums[que.front()]};
        for(int i = k; i < n; ++i)
        {
            while (!que.empty() && nums[i] >= nums[que.back()])
            {
                que.pop_back();
            }
            que.push_back(i);            
            while (que.front() <= i-k)
            {
                que.pop_front();
            }
            res.push_back(nums[que.front()]);
        }
        return res;
    }
};

// 分块 + 预处理
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    }
};

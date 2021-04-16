// 方法1 排序
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k,0);
        sort(arr.begin(),arr.end());
        for(int i = 0; i < k;++i)
        {
            vec[i] = arr[i];
        }
        return vec;
    }
};

// 方法2 堆
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k,0);
        if(0 == k)
            return vec;
        
        priority_queue<int> priority_que;       // 优先队列 底层堆
        for(int i = 0; i < k;++i)
        {
            priority_que.push(arr[i]);            
        }   
        for(int i = k; i < (int)arr.size(); ++i)
        {
            if(priority_que.top() > arr[i])
            {
                priority_que.pop();
                priority_que.push(arr[i]);
            }
        }
        for(int i = 0; i < k; ++i)
        {
            vec[i] = priorty_que.top();
            priority_que.pop();
        }
        return vec;

    }
};

// 方法3 快排思想    懒得看了意思不大   掌握堆排吧
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
    }
};
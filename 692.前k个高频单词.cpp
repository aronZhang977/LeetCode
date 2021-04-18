/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start

#include<string>
#include<unordered_map>

// 写法1：

class Solution {
public:
/*
    1.遍历，使用哈希表统计词频
    2.堆排
*/
    static bool cmp(pair<string,int>& m, pair<string,int>& n )
    {
        return m.second == n.second ? (m.first < n.first) : (m.second > n.second);
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;   
        for(auto& word : words)
        {
            ++map[word];
        }

        priority_queue<pair<string,int>, vector<pair<string,int> >,decltype(&cmp)> que(cmp);
        for(auto it = map.begin();it != map.end(); ++it)
        {
            que.emplace(*it);
            if(que.size() > k)
            {
                que.pop();
            }            
        }
        /*
        vector<string> res;
        while(!que.empty())
        {
            res.emplace_back(que.top().first);
            que.pop();
        }
        reverse(res.begin(),res.end());
        */
        vector<string> res(k);
        while(k-- > 0)
        {
            res[k] = que.top().first;
            que.pop();
        }   

        return res;
    }
};

// 写法2:
class MyCmp
{
public:
    bool operator()(const pair<string,int>& m,const pair<string,int>& n)
    {
        return m.second == n.second ? (m.first < n.first) : (m.second > n.second);
    }
};

class Solution {
public:
/*
    1.遍历，使用哈希表统计词频
    2.堆排
*/
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;   
        for(auto& word : words)
        {
            ++map[word];
        }

        priority_queue<pair<string,int>, vector<pair<string,int>>, MyCmp> que;
        for(auto it = map.begin();it != map.end(); ++it)
        {
            que.emplace(*it);
            if(que.size() > k)
            {
                que.pop();
            }            
        }
        /*
        vector<string> res;
        while(!que.empty())
        {
            res.emplace_back(que.top().first);
            que.pop();
        }
        reverse(res.begin(),res.end());
        */
        vector<string> res(k);
        while(k-- > 0)
        {
            res[k] = que.top().first;
            que.pop();
        }   

        return res;
    }
};

// @lc code=end


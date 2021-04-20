// 双指针
class Solution {
public:
    char firstUniqChar(string s) {
        for(int i = 0; i < s.size(); ++i)
        {
            int lIndex = 0,rIndex = s.size() - 1;
            while(lIndex < rIndex && s[lIndex] != s[i])
                ++lIndex;
            while(lIndex < rIndex && s[rIndex] != s[i])
                --rIndex;
            if (lIndex == rIndex)
                return s[i];            
        }
        return ' ';
    }
};

// 使用哈希表存储频数
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> cnts;
        for(auto& c : s)
            ++cnts[c];
        for(auto& c : s)
        {
            if(1 == cnts[c])
                return c;

        }
        return ' ';
    }
};

// 使用哈希表存储索引
class Solution {
public:
    char firstUniqChar(string s) {

    }
};

// 队列
class Solution {
public:
    char firstUniqChar(string s) {

    }
};
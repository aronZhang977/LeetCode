// 三次反转 剑指offer上的思路
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.end()-n);
        reverse(s.begin()+s.size()-n,s.end());;
        return s;
    }
};

// 字符串拼接与切分
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        len = s.size();
        s += s;
        return s.substr(n,len);
    }
};
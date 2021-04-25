class Solution {
public:
    string reverseWords(string s) {
        // 原地置换
class Solution {
public:
    string reverseWords(string s) {
        // 反转整个单词
        reverse(s.begin(),s.end());

        int n = s.size();
        int idx = 0;
        for(int start = 0;start < n; ++start)
        {
            if(s[start] != ' ')
            {
                // 填写一个空白字符，然后将idx移动到下一个单词开头的位置
                if(idx != 0)
                    s[idx++] = ' ';
                // 循环遍历至单词的末尾，并且移动反转过得单词位置 idx的位置也在更新
                int end = start;
                while(end < n && s[end] != ' ')
                    s[idx++] = s[end++];
                // 反转单词 相当于再反正了
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};
  
// 双端队列
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        // 去掉字符串开头的空白字符
        while (left <= right && s[left] == ' ') ++left;

        // 去掉字符串末尾的空白字符
        while (left <= right && s[right] == ' ') --right;

        deque<string> d;
        string word;

        while (left <= right) {
            char c = s[left];
            if (word.size() && c == ' ') {
                // 将单词 push 到队列的头部
                d.push_front(move(word));
                word = "";
            }
            else if (c != ' ') {
                word += c;
            }
            ++left;
        }
        d.push_front(move(word));
        
        string ans;
        while (!d.empty()) {
            ans += d.front();
            d.pop_front();
            if (!d.empty()) ans += ' ';
        }
        return ans;
    }
};

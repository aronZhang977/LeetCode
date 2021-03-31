/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."

*/

class Solution {
public:
    string replaceSpace(string s) {
    // 拷贝新串
    string str_new;
    for(auto &c : s)
    {
        //遍历拷贝
        if(' ' == c)
        {
            str_new.push_back('%');
            str_new.push_back('2');
            str_new.push_back('0');
        }
        else{
            str_new.push_back(c);
        }
    }
    return str_new;        
    }
};


//  最优解  耗时0ms ？
class Solution {
public:
    string replaceSpace(string s) {
        // 用string的replace函数
        int length = s.length();
        while(length >=  0)
        {
            if(' ' == s[length])
            {
                s.replace(length , 1, "%20");
            }
            length--;
        }
        return s;    
    }
};



class Solution {
public:
    string replaceSpace(string s) {
        // 双指针法 内存消耗最低
        //  先遍历一次统计空格的数量
        int count = 0; 
        int sOldSize = s.size();
        for (int i = 0; i != s.size(); ++i)
        {
            if(' ' == s[i])
            {
                ++count;
            }
        }
        s.resize(s.size() + count * 2);
        int sNewSize = s.size();
        for(int i = sNewSize - 1, j = s.size() -1; j < i; --i,--j)
        {
            if(s[j] != ' ')
            {
                s[i] = s[j];
            }
            else{
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};


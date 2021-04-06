/*

输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 

说明：

用返回一个整数列表来代替打印
n 为正整数
*/

//无脑解
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int mark_num = 1;
        int i = 1;
        while(i++ < n)
            mark_num *= 10;

       while(i != mark_num)
        {
            res.push_back(i++);
        }
        return res;
    }
};

// 本题主要考察用字符串解决大数越界问题


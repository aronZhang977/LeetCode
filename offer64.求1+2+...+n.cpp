// 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

// 逻辑运算符的短路性质
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n-1));
        return n;
    }
};

// 陈独秀  n*(n+1)/2
class Solution {
public:
    int sumNums(int n) {
        bool arr[n][n + 1];
        return sizeof(arr) >> 1;
    }
};

// 书上提供了三种思路
// 利用构造函数求解

// 利用虚函数来做if判断

// 利用函数指针求解

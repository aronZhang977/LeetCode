/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

 

示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：

输入：x = 2.10000, n = 3
输出：9.26100
示例 3：

输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
 

提示：

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104
 

注意：本题与主站 50 题相同：https://leetcode-cn.com/problems/powx-n/

*/

class Solution {
public:
    double myPow(double x, int n) {
        if (0 == n)
            return 1;
        if (1 == n)
            return x;
        double res = 0;
        if (n < 0)
            res = myPow(x, n / 2 * -1);
        else
            res = myPow(x,n >> 1);
        res *= res;
        // 奇数幂要单乘一个x
        if((n & 0x1) == 1)
            res *= x;
        return n < 0 ? 1/res:res;
    }
};

// 递归效率太低  试试迭代法。

class Solution {
public:

   double myPow(double x, int n) 
   {
       // 迭代法  
        long long temp_n = n;
        if(temp_n < 0)
            temp_n *= -1;
        double res = 1, temp_x = x;
        while (temp_n > 0)
        {
            // 这个地方多乘一个temp_x 和 x 值是不一样的
            if((temp_n & 0x1) == 1)
                res *= temp_x;
            temp_x *= temp_x;
            temp_n = temp_n >> 1;
        }
        return n < 0 ? 1 / res : res;
   }
};
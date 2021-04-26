// 数学+递归
class Solution {
public:
    int func(int n,int m)
    {
        if(1 == n)
            return 0;

        int x = func(n-1,m);
        return (m + x) % n;
    }

    int lastRemaining(int n, int m) {
        return func(n,m);    
    }
};
// 数学+迭代
class Solution {
public:
    int lastRemaining(int n, int m) {
        int f = 0;
        for(int i = 2; i != n + 1; ++i)
        {
            f = (m + f) % i;
        }
        return f;
    }
};
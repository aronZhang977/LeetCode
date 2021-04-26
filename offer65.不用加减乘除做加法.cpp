// c++不支持负数的移位，需要加上转换为非负数后操作

class Solution {
public:
    int add(int a, int b) {
        while(b != 0)
        {
            int c = (a & b) << 1;  //进位
            a ^= b;  // a = 非进位和
            b = c;   //b = 进位
        }
        return a;
    }
};
class Solution {
public:
    int add(int a, int b) {
        // 后续用a表示非进位和，b表示进位，当进位为0，则表示计算结束
        return b == 0 ? a : add(a ^ b, (unsigned int)(a & b) << 1);
    }
};

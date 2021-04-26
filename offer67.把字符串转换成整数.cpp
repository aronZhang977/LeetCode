class Solution {
public:
    int strToInt(string str) {
        int res = 0, i = 0;
        bool flag = true;
        // 过空格
        while(str[i] == ' ')
        {
            ++i;
        }
        // 检查符号
        if(str[i] == '-')
            flag = false;
        if(str[i] == '+' || false == flag)
            ++i;
        // 数字检查
        for(; i < str.size(); ++i)
        {
            int r = str[i] - '0';
            // 此处可用 isdigit(str[i]);
            if(str[i] >= '0' && str[i] <= '9')
            {
                //INT_MAX=2147483647
                if(res >  INT_MAX/10 || (INT_MAX/10 == res && r > 7))
                    return flag ? INT_MAX : INT_MIN;
                res = 10 * res +r;
            }else 
                break;
        }
        return flag ? res : -res;
    }
};
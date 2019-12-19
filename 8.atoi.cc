//1.丢弃无用开头空格
//2.如果第一个非空字符为正或者负号   
//3.忽略非有效字符
//4、非法输入：第一个非空字符串不是一个整数字符串、字符串为空
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int ret = 0;
        int flag =1;
        int index = 0;
        while(str[index] != ' ')
        {
            ++index;
        }
        if(str[index] == '-')
        {
            ++index;
            flag = -1;
        }else if(str[index] == '+')
        {
            ++index;
        }

        while( index < str.size() && (str[index]<='9' && str[index] >= '0' ))
        {
            int curr = str[index++] - '0';
            if(flag > 0 && (ret > INT_MAX/10 || ret*10 > INT_MAX -curr))
            {
                return INT_MAX;                
            }
            if(flag<0 && (ret < INT_MIN/10 || ret*10 < INT_MIN + curr ))
            {
                return INT_MIN;                
            }
            ret = ret*10 +  flag*curr;
        }
        return ret;        
        
    }
};

//1.丢弃无用开头空格
//2.如果第一个非空字符为正或者负号   
//3.忽略非有效字符
//4、非法输入：第一个非空字符串不是一个整数字符串、字符串为空
//



class Solution {
public:
    int myAtoi(string str) {
        int ret = 0;
        //int index = str.find_first_not_of(' ');
        int flag =1;
        //if(index == -1) return 0;
        int index = 0;
        while(str[index] == ' ' && index < str.size())
        {
            index++;
        }
                     
        
        if(str[index] == '-')
        {
            flag=-1;
            index++;
        }else if(str[index] == '+')
            index++;
            
        while( index < str.size())
        {
            if(!(str[index]<='9' && str[index]>='0'))
            {
                break;
            }
            int curr = str[index++] - '0';
            if(flag > 0 && (ret > INT_MAX/10 || ret*10 > INT_MAX -curr))
            {
                return INT_MAX;                
            }
            if(flag<0 && (ret < INT_MIN/10 || ret*10 < INT_MIN +curr ))
            {
                return INT_MIN;                
            }
            ret = ret*10 +  flag*curr;
        }
        return ret;        
        
    }
};
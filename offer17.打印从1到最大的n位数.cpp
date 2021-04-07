/*

输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 

说明：

用返回一个整数列表来代替打印
n 为正整数
*/

//暴力解   没有考虑到大数越界的问题
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int mark_num = 1;
        int i = 0;
        while(i != n)
        {
            mark_num *= 10;
            ++i;
        }
          
        for(int j = 1; j != mark_num;++j)
        {
            res.push_back(j);
        }
        return res;
    }
};

// 本题主要考察用字符串解决大数越界问题
//  char版

class Solution {
public:
    vector<int> m_res;

    vector<int> printNumbers(int n) {
        if(n <= 0)
            return m_res;
        // 创建一个能容纳最大值的字符数组，由于有异味要存储‘\0’，因此要开大一格
        char* number = new char[n + 1];
        // 初始化为0
        memset(number,'0',n);
        number[n] = '\0';
        while(!Increment(number))
        {
            printNumbers(number);
        }
        delete[] number; // 释放内存
        return m_res;
    }
    // 这个接口对number进行递增1 的操作并且 判断是否小于等于n位最大值 越界返回 true
    bool Increment(char* number)  // 形参传递char*指针 
    {
        //检测是否越界
        bool isOverflow = false;
        // 存储进位
        int nTakeOver = 0;
        int nLength = strlen(number); //此处为n 不是n+1
        for(int i = nLength - 1; i>= 0; --i)
        {
            int nSum = number[i] - '0' + nTakeOver;
            // 第一位，先递增1  
            if(i == nLength - 1)
            {
                ++nSum;
            }
            // 有进位
            if(nSum > 9)
            {
                //  如果是最高位有进位，说明超过了给定的最大值
                if(0 == i)
                {
                    isOverflow = true;
                }
                else
                {
                    // 非最高位有进位,处理进位
                    nTakeOver = 1;
                    number[i] = nSum - 10 + '0';  
                }
            }
            else
            {
                /// 没有进位 ，设置数字并跳出循环
                number[i] = nSum + '0';
                break;
            }
            return isOverflow;
        }
    }    

    void PrintNumber(char* number)
    {
        string s = "";
        bool isBegin0 = true;
        while(*number != '\0')
        {
            if(isBegin0 && *number != '0')
                isBegin0 = false;
            if(!isBegin0)
            {
                s += *number;
            }
            ++number;
        }
        int num = stoi(s); //转为整数
        m_res.push_back(num);
    }

};

/// string 版

class Solution {
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		//创建一个能容纳最大值的字符数组
		string number(n, '0');
		//初始全部设置为0
		while (!Increment(number))
		{
			saveNumber(number);
		}
		return res;
	}
	bool Increment(string& number) {
		//注意要使用引用传递，否则无法修改number
		bool isOverflow = false;//检测是否越界
		int nTakeOver = 0;//存储进位
		int nLength = number.size();
		for (int i = nLength - 1; i >= 0; i--)
		{
			int nSum = number[i] - '0' + nTakeOver;
			if (i == nLength - 1)
				//如果是第一位，进位
			{
				nSum++;
			}
			if (nSum >= 10)//有进位
			{
				if (i == 0)
					//如果是最高位有进位，说明超过了给定得到最大值，越界
				{
					isOverflow = true;
				}
				else
				{
					nTakeOver = 1;
					number[i] = nSum - 10 + '0';//对第i位进行设置
				}
			}
			else//没有进位
				//设置第i位数字
				//并直接跳出循环
			{
				number[i] = nSum + '0';
				break;
			}
		}
		return isOverflow;
	}
	void saveNumber(string number)
		//由于此处输出，不需要修改number，因此不需要加引用
	{
		string s = "";
		bool isBegin0 = true;
		string::iterator it = number.begin();
		while (it != number.end())
		{
			if (isBegin0 && *it != '0') isBegin0 = false;
			if (!isBegin0)
			{
				s += *it;
			}
			it++;
		}
		int num = stoi(s);
		res.push_back(num);
	}
};


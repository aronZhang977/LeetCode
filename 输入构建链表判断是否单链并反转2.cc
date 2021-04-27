#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <iterator>
#include <algorithm>

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
    //找到只出现一次的出发点如果找不到任意选一个作为出发点
    string a;
    string b;
    unordered_map<string, string> datas;
    bool sign = true;
    unordered_set<string> begin;
    while (cin >> a)
    {
        if (a[0] == EOF)
        {
            break;
        }
        cin >> b;
        if (datas.find(a) == datas.end())
        {
            datas[a] = b;
        }
        else
        {
            sign = false;
        }
        //排除只出现一次的元素
        if (begin.find(a) == begin.end())
        { //a没有出现插入
            begin.insert(a);
        }
        else
        { //出现第二次删除
            begin.erase(begin.find(a));
        }
        if (begin.find(b) == begin.end())
        { //b没有出现插入
            begin.insert(b);
        }
        else
        { //出现第二次删除
            begin.erase(begin.find(b));
        }
    }
    if (sign == false)
    {
        cout << "NO" << endl;
        return 0;
    }
    string beg; //单链表开始结点的值
    if (!begin.empty())
    {
        for (auto &s : begin)
        {
            if (datas.find(s) != datas.end())
            {
                beg = s;
            }
        }
    }
    if (beg.empty())
    {
        cout << "NO" << endl;
        return 0;
    }
    vector<string> result;
    while (!datas.empty())
    {
        result.push_back(beg);
        if (datas.find(beg) == datas.end())
        {
            break;
        }
        else
        {
            string tem = datas[beg];
            datas.erase(beg);
            beg = tem;
        }
    }
    result.push_back(beg);
    reverse(result.begin(), result.end());
    if (datas.empty())
    {
        for (size_t i = 0; i < result.size(); i++)
        {
            cout << result[i] << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
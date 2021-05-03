#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    //找到只出现一次的出发点如果找不到任意选一个作为出发点
    string str1, str2;
    unordered_map<string, string> map;
    bool flag = true;
    unordered_set<string> head;
    while (cin >> str1)
    {
        cin >> str2;
        if (map.find(str1) == map.end())
        {
            map[str1] = str2;
        }
        else
        {
            flag = false;
        }
        // 找头
        if (head.find(str1) == head.end())
        { 
            head.insert(str1);
        }
        else
        { 
            head.erase(head.find(str1));
        }
        if (head.find(str2) == head.end())
        { 
            head.insert(str2);
        }
        else
        { 
            head.erase(head.find(str2));
        }
    }
    if (flag == false)
    {
        cout << "NO" << endl;
        return 0;
    }
    string strHead;
    if (!head.empty())
    {
        for (auto str : head)
        {
            if (map.find(str) != map.end())
            {
                strHead = str;
            }
        }
    }
    if (strHead.empty())
    {
        cout << "NO" << endl;
        return 0;
    }
    vector<string> res;
    while (!map.empty())
    {
        res.push_back(strHead);
        if (map.find(strHead) == map.end())
        {
            break;
        }
        else
        {
            string tem = map[strHead];
            map.erase(strHead);
            strHead = tem;
        }
    }
    res.push_back(strHead);
    reverse(res.begin(), res.end());
    if (map.empty())
    {
        for (int i = 0; i < (int)res.size(); ++i)
        {
            cout << res[i] << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
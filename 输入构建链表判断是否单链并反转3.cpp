#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <iterator>
#include <algorithm>

int main()
{
    string str1,str2;
    unordered_map<string,string> map;
    vector<string> vStr1,vStr2;
    bool flag = true;
    while(cin >> str1)
    {
        cin >> str2;
        if(map.find(str1) == map.end())
        {
            map[str1] = str2;
            vStr1.push_back(str1);
            vStr2.push_back(str2);
        }
        else{
            flag = false;
        }
    }
    // 排除树
    if(!flag)
    {
        cout << "NO" << endl;
        return 1;
    }

    // 排除环和图
    unordered<string> set;
    for(string str : vStr2)
    {
        if(set.find(str) != set.end())
        {
            cout << "NO" << endl;
            return 1;
        }
        set.insert(str);
    }
    // 排除环 和断链
    int count = 0;
    for(int i = 0; i < (int)vStr1.size();++i)
    {
        auto it = find(vStr2.begin(),vStr2.end(), vStr1[i]);
        if(it == vStr2.end())
        {
            ++count;
             
        }
    }



    
}
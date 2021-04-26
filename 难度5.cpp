#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <iterator>
#include <algorithm>

using namespace std;

bool creatMap(unordered_map<string,string>& map,vector<string>& vStr1,vector<string>& vStr2)
{
	string str1,str2;
	
	while(cin >> str1)
	{
		if (str1[0] == EOF)
			break;
		
		cin >> str2;
		if(map.find(str1) == map.end())
		{
			map[str1] = str2;
			vStr1.push_back(str1);
			vStr2.push_back(str2);
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool checkStr2(vector<string>& vStr2)
{
	unordered_set<string> set;
	for(string str : vStr2)
	{
		if(set.find(str) != set.end())
			return false;
		set.insert(str);
	}
	return true;
}

bool findHead(vector<string>& vStr1, vector<string>& vStr2, string& strHead)
{
	int count = 0;
	for(int i = 0; i < vStr1.size(); ++i)
	{
		auto it = find(vStr2.begin(), vStr2.end(), vStr1[i]);
		if(it == vStr1.end())
		{
			//没找到
			if(++count > 1)
			{
				return false;
			}
			strHead = vStr1[i];			
		}
	}
	return true;	
}

vector<string> creatVector(unordered_map<string,string>& map,string& strHead)
{
	string tail;
	vector<string> res;
	auto it = map.find(strHead);
	while(it != map.end())
	{
		res.push_back(it->first);
		tail = it->second;
		it = map.find(it->second);
	}
	res.push_back(tail);
	
	return res;
}

int main()
{
	unordered_map<string,string> map;
	vector<string> vStr1;
	vector<string> vStr2;
	string strHead;
	if(!creatMap(map,vStr1,vStr2))
	{
		// 树状
		cout << "NO" << endl;
	}
	
	if(!checkStr2(vStr2) && !findHead(vStr1, vStr2, strHead))
	{
		//有环/图/断链
		cout << "NO" << endl;
	}
	
	// 用map构建链表的vector
	vector<string> res = creatVector(map, strHead);	
	
	//反转 
	reverse(res.begin(), res.end());	
	
	// 输出
	for(auto n : res)
	{
		cout << n <<endl;
	}
	
	return 0;
}
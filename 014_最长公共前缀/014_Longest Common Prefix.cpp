// 014_Longest Common Prefix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 编写一个函数来查找字符串数组中最长的公共前缀字符串

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs)
{
	char compare;
	string res;
	if (strs.empty()) return res;
	if (strs[0].empty()) return res;
	int min_str_size = strs[0].size();
	for (int i = 1; i < strs.size(); i++)
	{
		if (strs[i].size() < min_str_size) min_str_size = strs[i].size();
	}
	for (int i=0; i < min_str_size; i++)
	{
		compare = strs[0][i];
		for (int j=0; j < strs.size(); j++)
		{
			if (compare != strs[j][i]) return res;
		}
		res.push_back(compare);
	}
	return res;
}
int main()
{ 
	vector<string> strs = { "cad","ca" };
	cout << longestCommonPrefix(strs) << endl;
}

// 020_Valid Parentheses.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

//有效字符串需满足：

//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
bool isValid_wrong(string s)
{
	unordered_map<char, int> map1 = { {'[',0},{'{',0},{'(',0} };
	unordered_map<char, char> map2 = { {']','['},{'}','{'},{')','('} };
	//vector<char> kh;
	for (auto it = s.begin(); it != s.end(); it++)
	{
		if (map1.find(*it) != map1.end())
		{
			map1[*it] += 1;
		}
		else
		{
			if (map1[map2[*it]]>0)
			{
				map1[map2[*it]] -= 1;
			}
			else
			{
				return false;
			}
		}
	}
	if (map1['[']+ map1['{']+ map1['(']==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isValid(string s)
{
	unordered_map<char, int> map1 = { {'[',0},{'{',0},{'(',0} };
	unordered_map<char, char> map2 = { {']','['},{'}','{'},{')','('} };
	vector<char> kh;
	for (auto it = s.begin(); it != s.end();)
	{
		if (map1.find(*it)!=map1.end())
		{
			it++;
			continue;
		}
		else
		{
			if (map2[*it]==*(it-1))
			{
				it = s.erase(it);
				it = s.erase(it - 1);
			}
			else
			{
				return false;
			}
		}
	}
	if (s.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	cout << isValid_wrong("([)]") << endl;
	cout << isValid("([)]") << endl;
	cout << isValid("{()}") << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

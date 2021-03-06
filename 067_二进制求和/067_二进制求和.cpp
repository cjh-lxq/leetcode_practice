// 067_二进制求和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定两个二进制字符串，返回他们的和（用二进制表示）。
//
//输入为非空字符串且只包含数字 1 和 0。
//
//示例 1:
//
//输入: a = "11", b = "1"
//	输出 : "100"
//	示例 2 :
//
//	输入 : a = "1010", b = "1011"
//	输出 : "10101"
//
#include "pch.h"
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
string addBinary(string a, string b)
{
	bool jinwei = false;
	int add_num = 0, numa = 0, numb = 0;
	int max_i = max(a.size(), b.size());
	string res;
	int ita = a.size()-1;
	int itb = b.size()-1;
	for (int i=0;i<max_i;i++)
	{
		if (ita >= 0) numa = a[ita]-48;
		else numa = 0;
		if (itb >= 0) numb = b[itb]-48;
		else numb = 0;
		ita--;
		itb--;
		add_num = numa + numb + jinwei;
		if (add_num > 1)
		{
			jinwei = true;
			res = to_string(add_num - 2) + res;
		}
		else
		{
			jinwei = false;
			res = to_string(add_num) + res;
		}
	}
	if (jinwei) res = "1" + res;
	return res;
}
int main()
{
	cout << addBinary("11","1") << endl;
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

// 058_最后一个单词的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
//如果不存在最后一个单词，请返回 0 。
//说明：一个单词是指由字母组成，但不包含任何空格的字符串。

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int lengthOfLastWord(string s)
{
	int leng = 0;
	auto it = s.end();
	it--;
	for (;it!=s.begin();) //先删除尾部的空格再判断
	{
		if (*it == ' ')
		{
			it = s.erase(it) - 1;
		}
		else break;
	}
	for (it = s.begin(); it != s.end(); it++)
	{
		if (*it == ' ') leng = 0;
		else leng++;
	}
	return leng;
}
int main()
{
	cout << lengthOfLastWord("hello  ") << endl;
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

// 171_Excel表列序号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 2018-12-10
//给定一个Excel表格中的列名称，返回其相应的列序号。
//
//例如，
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int titleToNumber(string s)
{
	// 本质是26进制转10进制
	if (s.empty()) return 0;
	int res = 0;
	for (auto it = s.begin(); it != s.end(); it++)
	{
		res = (*it - 'A' + 1) + res * 26;
	}
	return res;
}
int main()
{
	cout << titleToNumber("AB") << endl;
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

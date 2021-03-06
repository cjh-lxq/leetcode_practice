// 038_报数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 被读作  "one 1"  ("一个一"), 即 11。
//11 被读作 "two 1s" ("两个一"）, 即 21。
//21 被读作 "one 2", "one 1" （"一个二", "一个一"), 即 1211。
//
//	给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
//
//	注意：整数顺序将表示为一个字符串。
// 在n很大时，程序运行极慢
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string count1(const string& str)
{
	string res;
	char str_count=str[0];
	int num=0;//注意这里初始化为0
	for (int i=0;i<str.size();i++)
	{
		if (str[i] == str_count)
		{
			num++;
		}
		else
		{
			res = res + to_string(num) + str_count;
			str_count = str[i];
			num = 1;//这里则要初始化为1
		}
	}
	res = res + to_string(num) + str_count;
	return res;
}
string countAndSay(int n)
{
	string last_string = "1";
	for (int i = 1; i < n; i++)
	{
		last_string = count1(last_string);
		cout << last_string << endl;
	}
	return last_string;
}
int main()
{
	countAndSay(10);
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

// 125_验证回文串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 2018-12-8
//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//说明：本题中，我们将空字符串定义为有效的回文串。
//
//示例 1:
//
//输入: "A man, a plan, a canal: Panama"
//	输出 : true
//	示例 2 :
//
//	输入 : "race a car"
//	输出 : false

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isPalindrome(string s)
{
	if (s.empty())return true;
	int id_left = 0;
	int id_right = s.size() - 1;
	char l = 0;
	char r = 0;
	while (id_right - id_left > 0)
	{
		l = s[id_left];
		r = s[id_right];
		for (; ispunct(s[id_left]) || s[id_left] == ' '; id_left++);
		l = s[id_left];
		for (; ispunct(s[id_right]) || s[id_right] == ' '; id_right--);
		r = s[id_right];
		if (toupper(s[id_left]) != toupper(s[id_right]))
			return false;
		id_left++;
		id_right--;
	}
	return true;
}
int main()
{
	string s = "A man8, a plan, a canal: Pa8nama";
	cout << isPalindrome(s) << endl;
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

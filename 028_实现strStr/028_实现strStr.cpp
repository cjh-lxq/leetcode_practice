// 028_实现strStr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个 haystack 字符串和一个 needle 字符串，
//在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
//当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
//对于本题而言，当 needle 是空字符串时我们应当返回 0 。
//这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
//但是标准答案是返回-1
//这道题应该是考KMP算法，但是不会
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int strStr(string haystack, string needle)
{
	return haystack.find(needle);
}
int main()
{
	cout << strStr("helloworld", "lll") << endl;
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

// 069_x的平方根.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//实现 int sqrt(int x) 函数。
//计算并返回 x 的平方根，其中 x 是非负整数。
//由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

#include "pch.h"
#include <iostream>
using namespace std;
int mySqrt_slow(int x) 
{
	long long x_long = x;
	//if (x < 4) return x;
	//int half = x / 2;
	long long i = 1;
	for (; i*i <= x; i++);
	return i - 1;
}
int mySqrt(int x)
{
	long long x_long = x;
	int half = x / 2;
	long long i = 1;
	while (true)
	{
		if(i*i<x_long && half*half>x_long)
	}
	return i - 1;
}
int main()
{
	cout <<mySqrt(2147395600) << endl;
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

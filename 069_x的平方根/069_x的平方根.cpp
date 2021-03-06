// 069_x的平方根.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//实现 int sqrt(int x) 函数。
//计算并返回 x 的平方根，其中 x 是非负整数。
//由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

#include "pch.h"
#include <iostream>
using namespace std;
int mySqrt_very_slow(int x) 
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
	//if (x < 2) return x;
	//使用二分法加快速度
	long long x_long = x;
	long long i = x / 2;
	long long i_right = x / 2, i_left = 0;
	long long i_mult = 0;
	while (true)
	{
		i_mult = i * i;
		if (i_mult == x_long)return i;
		if (i_mult > x_long)
		{
			if ((i - 1)*(i - 1) <= x_long) return i - 1;
			i_right = i;
			i = (i + i_left) / 2;
		}
		if (i_mult < x_long)
		{
			if ((i + 1)*(i + 1) > x_long) return i;
			if ((i + 1)*(i + 1) == x_long) return i+1;
			i_left = i;
			i = (i + i_right) / 2;
		}
	}
}
int main()
{
	//cout << mySqrt(2147395600) << endl;
	//cout << mySqrt(0) << endl;
	cout << mySqrt(1) << endl;
	cout << mySqrt(2) << endl;
	cout << mySqrt(3) << endl;

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

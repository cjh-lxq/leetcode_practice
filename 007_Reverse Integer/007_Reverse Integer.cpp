// 007_Reverse Integer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include <iostream>
#include <vector>
#include <limits.h> //最大值
using namespace std;
int reverse(int x)
{
	long long res = 0;//res不能是int型,也不能是long型
	while (x/10 != 0)
	{
		int yu = x % 10;
		x = x / 10;
		res = res * 10 + yu;
	}
	res = res * 10 + x;
	if (res<INT_MIN || res>INT_MAX)
	{
		return 0;
	}
	else
	{
		return res;
	}
}
int main()
{
    //std::cout << "Hello World!\n"; 
	cout << reverse(-2147483647) << endl;
	system("pause");
}


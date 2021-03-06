// 191_位1的个数(汉明重量).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 2018-12-12
// 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。
//
//  示例 1 :
//
//  输入 : 11
//	输出 : 3
//	解释 : 整数 11 的二进制表示为 00000000000000000000000000001011
//
//
//	示例 2 :
//
//	输入 : 128
//	输出 : 1
//	解释 : 整数 128 的二进制表示为 00000000000000000000000010000000

#include "pch.h"
#include <iostream>
#include <bitset>
using namespace std;
//https://www.cnblogs.com/graphics/archive/2010/06/21/1752421.html
int hammingWeight_bitset(uint32_t n)
{
	bitset<sizeof(uint32_t)> a = n;
	return a.count();
}
int hammingWeight(uint32_t n)
{
	int res = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((n & 1) == 1) ++res;
		n >>= 1;
	}
	return res;
}
int main()
{
	cout << hammingWeight_bitset(3) << endl;
	cout << hammingWeight(3) << endl;
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

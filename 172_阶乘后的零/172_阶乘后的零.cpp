// 172_阶乘后的零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 2018-12-10
//给定一个整数 n，返回 n!结果尾数中零的数量。
//
//示例 1:
//
//输入: 3
//	输出 : 0
//	解释 : 3 != 6, 尾数中没有零。
//	示例 2 :
//
//	输入 : 5
//	输出 : 1
//	解释 : 5 != 120, 尾数中有 1 个零.
//	说明 : 你算法的时间复杂度应为 O(log n) 。

#include "pch.h"
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;
typedef std::vector<int> BigInt;
BigInt factorial(int n)
{
	assert(n >= 0 && n <= 10000);
	BigInt result;
	result.push_back(1);
	for (int factor = 1; factor <= n; ++factor) {
		int carry = 0;
		for (auto& item : result) {
			int product = item * factor + carry;
			item = product % 10000;
			carry = product / 10000;
		}
		if (carry > 0) {
			result.push_back(carry);
		}
	}
	return result;
}

void printBigInt(const BigInt& number)
{
	if (number.empty())
	{
		printf("0\n");  // compiles to puts()
	}
	else
	{
		printf("%d", number.back());
		for (auto it = number.rbegin() + 1; it != number.rend(); ++it)
			printf("%04d", *it);
		printf("\n");
	}
}
int trailingZeroes_cjh(int n)
{
	int num_10 = 0;
	int num_5 = 0;
	num_10 = n / 10;
	num_5 = n / 5 - num_10;
	return num_10 + num_5;
}
int trailingZeroes(int n) 
{
	int count = 0;
	while (n > 1)
		count += (n /= 5);
	return count;
}

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout << trailingZeroes(30) << endl;
	BigInt res = factorial(30);
	for (auto it = res.rbegin(); it != res.rend(); it++)
	{
		cout << *it;
	}
	cout << endl;
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

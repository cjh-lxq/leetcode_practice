// 066_加一.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
// 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
// 你可以假设除了整数 0 之外，这个整数不会以零开头。

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> plusOne_shit(vector<int>& digits)
{
	long long num = 0;
	for (auto it = digits.begin(); it != digits.end(); it++)
	{
		num = num * 10 + *it;
	}
	num++;
	digits.clear();
	while (num / 10)
	{
		int yu = num % 10;
		digits.insert(digits.begin(), num % 10);
		num = num / 10;
	}
	digits.insert(digits.begin(),num);
	return digits;
}
vector<int> plusOne(vector<int>& digits)
{
	bool jinwei = false;
	int res = 0;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (i == digits.size() - 1) res = 1 + digits[i];
		else res = digits[i] + jinwei;
		if (res>=10)
		{
			digits[i] = res - 10;
			jinwei = true;
		}
		else
		{
			digits[i] = res;
			jinwei = false;
		}
	}
	if (jinwei) digits.insert(digits.begin(), 1);
	return digits;
}
int main()
{
	vector<int> nums = { 9,9 };
	plusOne(nums);
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it<<' ';
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

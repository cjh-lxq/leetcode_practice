// 027_ 移除元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int removeElement(vector<int>& nums, int val)
{
	for (auto it = nums.begin(); it != nums.end();)
	{
		if (*it == val)
		{
			it = nums.erase(it);
		}
		else
		{
			it++;
		}
	}
	return nums.size();
}
int main()
{
	vector<int> nums = { 0,1,2,2,3,0,4,2 };
	cout << removeElement(nums, 2) << endl;
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

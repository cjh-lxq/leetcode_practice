// 167_两数之和 II - 输入有序数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 2018-12-10
//给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
//
//函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
//
//说明 :
//
//返回的下标值（index1 和 index2）不是从零开始的。
//你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& numbers, int target)
{
	int start_index = 0;
	int end_index = numbers.size() - 1;
	int add_res = 0;
	vector<int> res = { 0,0 };
	while (start_index < end_index)
	{
		add_res = numbers[start_index] + numbers[end_index];
		if (add_res == target)
		{
			res = { start_index + 1,end_index + 1 };
			return res;
		}
		else
		{
			if (add_res > target) end_index--;
			else start_index++;
		}
	}
	return res;
}
int main()
{
	vector<int> nums = { 2,7,11,15 };
	twoSum(nums, 9);
    std::cout << "Hello World!\n"; 
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

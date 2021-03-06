// 035_搜索插入位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//你可以假设数组中无重复元素。

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target)
{
	int i = 0;
	for (; i < nums.size(); i++)
	{
		if (nums[i]<target)
		{
			continue;
		}
		else
		{
			return i;
		}
	}
	return i;
}
int main()
{
    //std::cout << "Hello World!\n"; 
	vector<int> nums = { 1,3,5,6 };
	cout << searchInsert(nums, 1) << endl;
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

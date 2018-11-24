// 001_twosum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.

//You may assume that each input would have exactly one solution, and you may not use the same element twice.
#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target)
{
	//使用哈希表来查找，速度快。
	vector<int> res;
	unordered_map<int, int> map1;
	for (int i=0;i<nums.size();i++)
	{
		int find_num = target - nums[i];
		if (map1.find(find_num)!=map1.end())
		{
			res.push_back(map1[find_num]);
			res.push_back(i);
			return res;
		}
		map1[nums[i]] = i;
	}
	return res;
}
int main()
{
	vector<int> num = { 7,9,14,67 };
	vector<int> res = twoSum(num,16);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout<<endl;
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

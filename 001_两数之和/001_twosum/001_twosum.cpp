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


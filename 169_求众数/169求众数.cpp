// 169求众数.cpp: 定义控制台应用程序的入口点。
// 2018-12-9
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
int majorityElement(vector<int>& nums)
{
	unordered_map<int, int> nums_map;
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		if (nums_map.find(*it) == nums_map.end())
		{
			nums_map[*it] = 1;
		}
		else
		{
			nums_map[*it] += 1;
		}
	}
	int half_size = nums.size() / 2;
	for (auto it = nums_map.begin(); it != nums_map.end(); it++)
	{
		if (it->second > half_size) return it->first;
	}
}
int main()
{
	vector<int> nums = { 2,2,1,1,1,2,2 };
	cout << majorityElement(nums) << endl;
	system("pause");
    return 0;
}


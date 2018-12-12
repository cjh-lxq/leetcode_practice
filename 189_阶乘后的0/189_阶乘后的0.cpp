// 189_旋转数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 2018-12-12
// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//  示例 1:
//
//  输入: [1, 2, 3, 4, 5, 6, 7] 和 k = 3
//	输出 : [5, 6, 7, 1, 2, 3, 4]
//	解释 :
//	向右旋转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右旋转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右旋转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//	示例 2 :
//
//	输入 : [-1, -100, 3, 99] 和 k = 2
//	输出 : [3, 99, -1, -100]
//	解释 :
//	向右旋转 1 步 : [99, -1, -100, 3]
//	向右旋转 2 步 : [3, 99, -1, -100]
//	说明 :
//
//	尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
//	要求使用空间复杂度为 O(1) 的原地算法。


#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<int>& nums, int k)
{
	int len_nums = nums.size();
	k = k % len_nums;
	if (k < 1 || nums.empty()) return;
	nums.insert(nums.begin(), nums.end() - k, nums.end());
	nums.erase(nums.end() - k, nums.end());
}
int main()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	rotate(nums,57843);
	for (auto it = nums.begin(); it != nums.end(); it++) cout << *it << " ";
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

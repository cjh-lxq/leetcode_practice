//088_合并两个有序数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组
//说明:
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//输入:
//nums1 = [1, 2, 3, 0, 0, 0], m = 3
//nums2 = [2, 5, 6], n = 3
//输出 : [1, 2, 2, 3, 5, 6] 
#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
void merge_create(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	vector<int> res;
	int id1 = 0, id2 = 0;
	while (id1 < m && id2 < n)
	{
		if (nums1[id1] <= nums2[id2])
		{
			res.push_back(nums1[id1]);
			id1++;
		}
		else
		{
			res.push_back(nums2[id2]);
			id2++;
		}
	}
	if (id1 >= m)
	{
		for (; id2 < n; id2++) res.push_back(nums2[id2]);
	}
	else
	{
		for (; id1 < m; id1++) res.push_back(nums1[id1]);
	}
	nums1 = res;
}
void merge_insert(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	auto it1 = nums1.begin();
	auto it2 = nums2.begin();
	int id1 = 0, id2 = 0;
	int last_num=0;
	while (id1 < m && id2 < n)
	{
		if (*it1 <= *it2)
		{
			it1++;
			id1++;
		}
		else
		{
			it1 = nums1.insert(it1, *it2);
			it2++;
			id2++;
		}
	}
	if (id1 >= m)
	{
		for (; id2 < n; id2++) nums1[m + id2] = nums2[id2];
		//if(last_num)
	}
	nums1.resize(m + n);
}
int main()
{
	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	vector<int> nums2 = { 2, 5, 6 };
	int m = 3, n = 3;
	merge_create(nums1, m, nums2, n);
	cout << "merge_create" << endl;
	for (int i = 0; i < m + n; i++)
	{
		cout << nums1[i] << " ";
	}
	cout << endl;
	nums1 = { 1, 2, 3, 0, 0, 0 };
	nums2 = { 2,5,6 };
	m = 3;
	n = 3;
	merge_insert(nums1, m, nums2, n);
	cout << "merge_insert" << endl;
	for (int i = 0; i < m + n; i++)
	{
		cout << nums1[i] << " ";
	}
	cout << endl;
	//下面的样例有问题
	nums1 = { 4,0,0,0,0,0 };
	nums2 = { 1,2,3,5,6 };
	m = 1;
	n = 5;
	merge_insert(nums1, m, nums2, n);
	cout << "merge_insert" << endl;
	for (int i = 0; i < m + n; i++)
	{
		cout << nums1[i] << " ";
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

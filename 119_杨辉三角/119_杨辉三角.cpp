// 119_杨辉三角.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 2018-12-6
//给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

#include "pch.h"
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
vector<int> getRow(int rowIndex)
{	
	vector<int> res_row;
	vector<int> last_row = { 1 };
	res_row = last_row;
	for (int i = 1; i <= rowIndex; i++)
	{
		res_row.clear();
		res_row.resize(i + 1,1);
		for (int j = 0; j < res_row.size(); j++)
		{
			if(j==0 || j==res_row.size()-1) continue;
			res_row[j] = last_row[j - 1] + last_row[j];
		}
		last_row = res_row;
	}
	return res_row;
}
int main()
{
	clock_t start_time, end_time;
	start_time = clock();
	vector<int> res = getRow(3);
	end_time = clock();
	cout << "time=" << (double)(end_time - start_time) / CLOCKS_PER_SEC << "s" << endl;
	for (auto it = res.begin(); it != res.end(); it++)
	{
		cout << *it << ' ';
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

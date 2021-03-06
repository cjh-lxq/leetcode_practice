// 118_杨辉三角型.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 2018-12-6
//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows)
{
	vector<int> res_col = { 1 };
	vector<vector<int>> res;
	if (numRows == 0)return res;
	res.push_back(res_col);
	for (int i = 1; i < numRows ; i++)
	{
		res_col.clear();
		res_col.resize(i + 1, 1);
		//杨辉三角的第i行有i+1个元素(为方便索引行数从0开始记)
		for (int j = 0; j < res_col.size(); j++)
		{
			if(j==0 || j==res_col.size()-1) continue;
			res_col[j] = res[i - 1][j - 1] + res[i - 1][j];
		}
		res.push_back(res_col);
	}
	return res;
}
int main()
{
	vector<vector<int>> res = generate(10);
	for (auto it1 = res.begin(); it1 != res.end(); it1++)
	{
		for (auto it2 = it1->begin(); it2 != it1->end(); it2++)
		{
			cout << *it2 << " ";
		}
		cout << endl;
	}
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

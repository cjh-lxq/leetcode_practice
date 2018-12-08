// 122_买卖股票的最佳时机II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 2018-12-8
//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//
//设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
//
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//
//示例 1:
//
//输入: [7, 1, 5, 3, 6, 4]
//	输出 : 7
//	解释 : 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
//	随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
//	示例 2 :
//
//	输入 : [1, 2, 3, 4, 5]
//	输出 : 4
//	解释 : 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
//	注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
//	因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
//	示例 3 :
//
//	输入 : [7, 6, 4, 3, 1]
//	输出 : 0
//	解释 : 在这种情况下, 没有交易完成, 所以最大利润为 0。

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices)
{
	if (prices.empty()) return 0;
	vector<int> profit;
	int min_prise = prices[0];
	for (auto it = prices.begin() + 1; it != prices.end(); it++)
	{
		if (*it < min_prise) min_prise = *it;
		if (*it > min_prise) profit.push_back(*it - min_prise);
	}
	vector<int>::iterator biggest = max_element(profit.begin(), profit.end());
	if (profit.empty()) return 0;
	else return *biggest;
}
int main()
{
	vector<int> prise = { 3,3,5,0,0,3,1,4 };
	cout << maxProfit(prise) << endl;
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

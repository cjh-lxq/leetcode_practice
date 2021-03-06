// 013_Roman to Integer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int romanToInt(string s)
{
	int res = 0;
	char last_word = 'o';
	unordered_map<char, int> map1={ {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
	for (int i=0;i<s.size();i++)
	{
		//第一，如果当前数字是最后一个数字，或者之后的数字比它小的话，则加上当前数字
		//第二，其他情况则减去这个数字
		int val = map1[s[i]];
		if (i==s.size()-1 || map1[s[i+1]]<= map1[s[i]])
		{
			res += val;
		}
		else
		{
			res -= val;
		}
	}
	return res;
}
int main()
{
	cout << romanToInt("MCMXCIV") << endl;
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

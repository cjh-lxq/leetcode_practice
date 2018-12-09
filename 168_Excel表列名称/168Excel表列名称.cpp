// 168Excel表列名称.cpp: 定义控制台应用程序的入口点。
// 2018-12-9
//给定一个正整数，返回它在 Excel 表中相对应的列名称。
//
//例如，
//
//1->A
//2->B
//3->C
//...
//26->Z
//27->AA
//28->AB
//...
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
string convertToTitle(int n)
{
	//这其实是一个10进制转26进制的问题
	if (n < 1) return " ";
	string res;
	int mod;
	char input_char;
	for (; n > 0;)
	{
		mod = n % 26;
		n = n / 26;
		if (mod == 0)
		{
			mod = 26;
			n -= 1;
		}
		input_char = 'A' + mod - 1;
		res = input_char + res;
	}
	return res;
}
int main()
{
	cout << convertToTitle(52) << endl;
	system("pause");
    return 0;
}


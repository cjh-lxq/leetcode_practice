// 155最小栈.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
class MinStack 
{
public:
	/** initialize your data structure here. */
	vector<int> stark_vec;
	unordered_map<int,int> stark_map;
	int min_num, pop_num;
	MinStack() 
	{
		min_num = 99999999999;
	}
	void push(int x) 
	{
		stark_vec.push_back(x);
		if (stark_map.find(x) == stark_map.end() || stark_map[x] == 0) stark_map[x] = 1;
		else stark_map[x] += 1;
		if (min_num > x) 
			min_num = x;
	}

	void pop() 
	{
		pop_num = *(stark_vec.end() - 1);
		stark_vec.erase(stark_vec.end() - 1);
		stark_map[pop_num] -= 1;
		if (stark_map[pop_num] == 0) min_num = *(min_element(stark_vec.begin(), stark_vec.end()));
	}

	int top() 
	{
		return *(stark_vec.end() - 1);
	}

	int getMin() 
	{
		return min_num;
	}
};

int main()
{
	MinStack s;
	s.push(-2);
	s.push(0);
	s.push(-3);
	cout << s.getMin() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << s.getMin() << endl;
	return 0;
	system("pause");
}


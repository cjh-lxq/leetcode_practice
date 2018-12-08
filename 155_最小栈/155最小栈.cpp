// 155最小栈.cpp: 定义控制台应用程序的入口点。
// 2018-12-8

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <stack>
using namespace std;
//这道最小栈跟原来的栈相比就是多了一个功能，可以返回该栈的最小值。使用两个栈来实现，一个栈来按顺序存储push进来的数据，另一个用来存出现过的最小值。代码如下:
class MinStack {
public:
	MinStack() { }
	void push(int x) 
	{
		if (stack_min.empty() || x <= stack_min.top()) stack_min.push(x);
		stark_num.push(x);
	}

	void pop() 
	{
		if (stack_min.top() == stark_num.top()) stack_min.pop();
		stark_num.pop();
	}

	int top() 
	{
		return stark_num.top();
	}

	int getMin() 
	{
		return stack_min.top();
	}
private:
	stack<long long> stark_num, stack_min;
};

void test1()
{
	MinStack s;
	s.push(-2);
	s.push(0);
	s.push(-3);
	cout << s.getMin() << endl;
	s.pop();
	cout << s.top() << endl;
	cout << s.getMin() << endl;
}
void test2()
{
	//["MinStack", "push", "push", "push", "top", "pop", "getMin", "pop", "getMin", "pop", "push", "top", "getMin", "push", "top", "getMin", "pop", "getMin"]
	//[[], [2147483646], [2147483646], [2147483647], [], [], [], [], [], [], [2147483647], [], [], [-2147483648], [], [], [], []]
	MinStack s;
	s.push(2147483646);
	s.push(2147483646);
	s.push(2147483647);
	cout << s.top() << endl;
	s.pop();
	cout << s.getMin() << endl;
	s.pop();
	cout << s.getMin() << endl;
	s.pop();
	s.push(2147483647);
	cout << s.top() << endl;
	cout << s.getMin() << endl;
	s.push(-2147483648);
	cout << s.top() << endl;
	cout << s.getMin() << endl;
	s.pop();
	cout << s.getMin() << endl;
}
int main()
{
	test2();
	system("pause");
	return 0;
}


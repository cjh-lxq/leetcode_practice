// 021_合并两个有序链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
void print_linklist(ListNode* l1)
{
	while (l1)
	{
		cout << l1->val;
		if (l1->next != NULL) cout << "->";
		l1 = l1->next;
	}
	cout << endl;
}
ListNode* create_linklist(vector<int> vec)
{
	ListNode* head = new ListNode(vec[0]);
	if (vec.size() <= 1) return head;
	ListNode* p = head;
	for (int i = 1; i < vec.size(); i++)
	{
		ListNode* new_node = new ListNode(vec[i]);
		p->next = new_node;
		p = new_node;
	}
	return head;
}
ListNode* create_linklist(int length)
{
	//生成链节
	vector<ListNode> listlink_vector;
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	for (int i = 2; i <= length; i++)
	{
		ListNode *node = new ListNode(i);
		p->next = node;
		p = node;
	}
	return head;
}
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
//{
//
//}

int main()
{
	ListNode* head = create_linklist({ 1,2,4,6,7 });
	print_linklist(head);
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

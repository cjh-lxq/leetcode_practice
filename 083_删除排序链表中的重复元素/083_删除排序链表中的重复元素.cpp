// 083_删除排序链表中的重复元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
//链节声明
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//反转链表
ListNode* recerse_nodelist(ListNode* head)
{
	//链表反转函数
	ListNode* p = NULL, *next_n = NULL;
	while (head != NULL)
	{
		next_n = head->next;
		head->next = p;
		p = head;
		head = next_n;
	}
	return p;
}

//生成链表1
ListNode* create_linklist_bylength(int length)
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
//生成链表2
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
//删除链表
void del_listlink(ListNode* head)
{
	//删除链节
	int num_node = 0;
	ListNode* p = head;
	while (head != NULL)
	{
		++num_node;
		p = head->next;
		delete head;
		head = p;
	}
	cout << num_node << " listnode is deleted" << endl;
}

//打印链表
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
ListNode* deleteDuplicates(ListNode* head)
{
	if (!head) return NULL;
	ListNode* p = head;
	ListNode* p_last = NULL;
	int num = head->val + 1;
	while (p)
	{
		if (p->val != num)
		{
			num = p->val;
			p_last = p;
			p = p->next;
		}
		else
		{
			p_last->next = p->next;
			delete p;
			p = p_last->next;
			//这种写法会回收内存，但是可能不能再网上运行
		}
	}
	return head;
}
int main()
{
	ListNode* l1 = create_linklist({ 5,1,1,2,2,4,4,4,4 });
	print_linklist(l1);
	deleteDuplicates(l1);
	print_linklist(l1);
	del_listlink(l1);
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

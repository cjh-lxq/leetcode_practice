// 002_Add Two Numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//You are given two non - empty linked lists representing two non - negative integers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.

//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//2018-11-24 未通过，写的什么辣鸡代码
//2018-11-27 通过
#include "pch.h"
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <string>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//int solve_num(ListNode *l1)
//{
//	int wei = 0;
//	int num = 0;
//	while (l1!=NULL)
//	{
//		num = num + pow((l1->val), wei);
//		wei++;
//		l1 = l1->next;
//	}
//	return num;
//}
//ListNode* int2linklist(int num)
//{
//	int wei = 1;
//	vector<int> num_wei;
//	while (true)
//	{
//		double num1;
//		
//
//	}
//	ListNode* head = new ListNode();
//}
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//{
//	int num_sum = solve_num(l1) + solve_num(l2);
//	
//}
ListNode* reverse_linklist(ListNode* l1)
{
	ListNode* p = NULL, *next_node = NULL;
	while (l1)
	{
		next_node = l1->next;
		l1->next = p;
		p = l1;
		l1 = next_node;
	}
	return p;
}
//ListNode* create_linklist(int length)
//{
//	//生成链节
//	vector<ListNode> listlink_vector;
//	ListNode *head = new ListNode(0);
//	ListNode *p = head;
//	for (int i = 2; i <= length; i++)
//	{
//		ListNode *node = new ListNode(i);
//		p->next = node;
//		p = node;
//	}
//	return head;
//}
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
void print_linklist(ListNode* l1)
{
	while (l1)
	{
		cout << l1->val<<" ";
		l1 = l1->next;
	}
	cout << endl;
}
ListNode* create_linklist(vector<int> vec)
{
	if (vec.empty()) return NULL;
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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	bool jinwei = false;
	int wei = 0;
	vector<int> res;
	while (l1 || l2)
	{
		if (l1 && l2)
		{
			wei = l1->val + l2->val + jinwei;
			l1 = l1->next;
			l2 = l2->next;
		}
		else
		{
			if (l1)
			{
				wei = l1->val + jinwei;
				l1 = l1->next;
			}
			if (l2)
			{
				wei = l2->val + jinwei;
				l2 = l2->next;
			}
		}
		if (jinwei) jinwei = false;
		if (wei >= 10)
		{
			res.push_back(wei - 10);
			jinwei = true;
		}
		else res.push_back(wei);
		wei = 0;
	}
	if (jinwei) res.push_back(1);
	return create_linklist(res);
}
int main()
{
	ListNode* l1 = create_linklist({1,8});
	ListNode* l2 = create_linklist({0});
	print_linklist(l1);
	print_linklist(l2);
	ListNode* res=addTwoNumbers(l1, l2);
	print_linklist(res);
	del_listlink(l1);
	del_listlink(l2);
	del_listlink(res);
}


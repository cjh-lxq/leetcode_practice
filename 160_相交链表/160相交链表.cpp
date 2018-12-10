// 160相交链表.cpp: 定义控制台应用程序的入口点。
// 2018-12-8
//编写一个程序，找到两个单链表相交的起始节点。
//
//
//
//例如，下面的两个链表：
//
//A : a1 → a2
//	↘
//	c1 → c2 → c3
//	↗
//	B : b1 → b2 → b3
//	在节点 c1 开始相交。
//
//
//
//	注意：
//
//	如果两个链表没有交点，返回 null.
//	在返回结果后，两个链表仍须保持原有的结构。
//	可假定整个链表结构中没有循环。

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
//判断两链表是否相交
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	unordered_set<ListNode*> linklist1_node_set;
	while (headA != NULL)
	{
		linklist1_node_set.emplace(headA);
		headA = headA->next;
	}
	while (headB != NULL)
	{
		if (linklist1_node_set.find(headB) != linklist1_node_set.end())
			return headB;
		headB = headB->next;
	}
	return NULL;
}
int main()
{
	ListNode* a_head = create_linklist({ 4,5,6 });
	ListNode* b_head = create_linklist({ 7,4,5,9,2,8 });
	ListNode* c_head = create_linklist({ 1,2,3 });
	//创建相交点
	ListNode* c_end = c_head;
	ListNode* b_mid = b_head;
	for (; c_end->next != NULL; c_end = c_end->next);
	for (; b_mid->val != 2; b_mid = b_mid->next);
	c_end->next = b_mid;
	getIntersectionNode(a_head, b_head);
	getIntersectionNode(b_head, c_head);
	del_listlink(a_head);
	del_listlink(b_head);
	del_listlink(c_head);
}


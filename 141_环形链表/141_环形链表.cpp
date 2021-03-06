// 141_环形链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 2018-12-8
//给定一个链表，判断链表中是否有环。
//
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//如果 pos 是 - 1，则在该链表中没有环。

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
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
bool hasCycle(ListNode *head)
{
	if (head == NULL || head->next == NULL) return false;
	ListNode* p_slow = head;
	ListNode* p_fast = head;
	while (true)
	{
		p_slow = p_slow->next;
		p_fast = p_fast->next->next;
		if ((p_fast == NULL || p_fast->next == NULL) && p_slow != NULL) return false;
		if (p_fast->val == p_slow->val) return true;
	}
}
int main()
{
	ListNode* head1 = create_linklist({ 3,2,0,4 });
	ListNode* head2 = create_linklist({ 3,2,0,4 });
	ListNode* wei = head1;
	for (; wei->next != NULL; wei = wei->next);
	wei->next = head1->next;
	cout << hasCycle(head1) << endl;
	cout << hasCycle(head2) << endl;
	//del_listlink(head1);
	del_listlink(head2);
	system("pause");
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

// 104_二叉树最大深度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//生成二叉树,构建一个完全二叉树,0为空节点
TreeNode* create_tree_ByVector(vector<int> tree_vec)
{
	//构建一个完全二叉树,0为空节点
	if (tree_vec.empty()) return NULL;
	vector<TreeNode*> node_vec;
	//先创建节点，只有值，没有left和right
	for (auto it = tree_vec.begin(); it != tree_vec.end(); it++)
	{
		if (*it != 0)
		{
			TreeNode* new_node = new TreeNode(*it);
			node_vec.push_back(new_node);
		}
		else node_vec.push_back(NULL);
	}
	TreeNode* head = node_vec[0];
	int node_depth = 0;//节点深度
	for (int id_node = 0; id_node < node_vec.size(); id_node++)
	{
		if (!node_vec[id_node]) continue; //是空就跳过
		//先计算节点在第几层
		while ((id_node + 1) / pow(2, node_depth) >= 2) node_depth++;
		//完全二叉树中，当第一个节点ID为0时，第I个节点的左子节点是第2I+1个，右子节点是第2I+2个
		if (id_node * 2 + 1 < node_vec.size())
			node_vec[id_node]->left = node_vec[id_node * 2 + 1];
		else node_vec[id_node]->left = NULL;
		if (id_node * 2 + 2 < node_vec.size())
			node_vec[id_node]->right = node_vec[id_node * 2 + 2];
		else node_vec[id_node]->right = NULL;
	}
	return head;
}
//删除整个树 递归
int delete_tree(TreeNode* head)
{
	int del_num = 1;
	if (!head) return 0;
	del_num += delete_tree(head->left);
	del_num += delete_tree(head->right);
	delete head;
	return del_num;
}
//求二叉树最大深度
int maxDepth(TreeNode* root)
{
	if (!root) return 0;
	int res = 1;
	res = max(maxDepth(root->left), maxDepth(root->right)) + 1;
	return res;
}
int main()
{
	TreeNode* head = create_tree_ByVector({ 1,2,3,4,5,0,6,7 });
	cout << maxDepth(head) << endl;
	delete_tree(head);
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

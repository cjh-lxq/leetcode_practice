// 108_将有序数组转换为二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
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
TreeNode* sortedArrayToBST(vector<int>& nums)
{
	if (nums.empty()) return NULL;
	int mid = nums.size() / 2;
	int left = mid, right = mid;
	TreeNode* head = new TreeNode(nums[mid]);
	TreeNode* p = head;
	while (left - 1 >= 0)
	{
		--left;
		TreeNode* new_node = new TreeNode(nums[left]);
		p->left = new_node;
		p = p->left;
	}
	p = head;
	while (right + 1 < nums.size())
	{
		++right;
		TreeNode* new_node = new TreeNode(nums[right]);
		p->right = new_node;
		p = p->right;
	}
	return head;
}
int main()
{
	vector<int> nums = { 0,1,2,3,4,5 };
	sortedArrayToBST(nums);
}
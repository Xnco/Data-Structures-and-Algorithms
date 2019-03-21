#include "pch.h";
#include <iostream>;
#include <vector>;
#include <stack>;

using namespace std;

#pragma region 589_N叉树的前序遍历
/*
给定一个 N 叉树，返回其节点值的前序遍历。
说明: 递归法很简单，你可以使用迭代法完成此题吗?
*/

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

// 340ms(0.73MB), 33.1MB
class Solution {
public:
	vector<int> preorder(Node* root) {
		if (root == NULL)
		{
			return {};
		}
		//vector<int> result = {};
		//PreOrder(root, result);
		//return result;

		vector<int> result;
		vector<int>* resultPointer = &result;
		PreOrder2(root, resultPointer);
		return *resultPointer;
	}

	void PreOrder(Node* root, vector<int>& result)
	{
		result.push_back(root->val);
		for (size_t i = 0; i < root->children.size(); i++)
		{
			PreOrder(root->children[i], result);
		}
	}

	void PreOrder2(Node* root, vector<int>* result)
	{
		result->push_back(root->val);
		for (size_t i = 0; i < root->children.size(); i++)
		{
			PreOrder2(root->children[i], result);
		}
	}

	vector<int> preorder2(Node* root) {
		if (root == NULL)
		{
			return {};
		}

		vector<int> result;
		stack<Node*> s;
		s.push(root);

		while (s.size() != 0)
		{
			Node* node = s.top();
			s.pop();
			result.push_back(node->val);
			for (size_t i = node->children.size() - 1; i > -1; i--)
			{
				s.push((node->children)[i]);
			}
		}
		return result;
	}
};
#pragma endregion
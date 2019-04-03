#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;
#include <math.h>
#include <algorithm>

using namespace std;

#pragma region 100_相同的树
/*
给定两个二叉树，编写一个函数来检验它们是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
示例 1:
输入:       1         1
		  / \       / \
		 2   3     2   3

		[1,2,3],   [1,2,3]

输出: true
示例 2:
输入:      1          1
		  /           \
		 2             2

		[1,2],     [1,null,2]

输出: false
示例 3:
输入:       1         1
		  / \       / \
		 2   1     1   2

		[1,2,1],   [1,1,2]

输出: false
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	// 4ms(100%), 9.8MB(99.4)
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr ^ q == nullptr)
		{
			return false;
		}
		if (p == nullptr && q == nullptr)
		{
			return true;
		}

		if (p->val == q->val)
		{
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		return false;
	}

	// 4ms, 9.6MB(100%)
	bool isSameTree2(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr)
		{
			return true;
		}
		if (p == nullptr || q == nullptr || p->val != q->val)
		{
			return false;
		}
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};
#pragma endregion
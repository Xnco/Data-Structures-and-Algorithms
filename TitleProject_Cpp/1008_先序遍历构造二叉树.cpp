
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 1008_先序遍历构造二叉树
/*
返回与给定先序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。
(回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则，对于 node.left 的任何后代，值总 < node.val，而 node.right 的任何后代，值总 > node.val。此外，先序遍历首先显示节点的值，然后遍历 node.left，接着遍历 node.right。）
示例：
输入：[8,5,1,7,10,12]
输出：[8,5,10,1,7,null,12]
提示：
1 <= preorder.length <= 100
先序 preorder 中的值是不同的。
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
public:
	// 8ms(86.9%), 11.1MB(100%)
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		return getRoot(preorder, 0, preorder.size() - 1);
	}

	TreeNode* getRoot(vector<int> & nums, int left, int right)
	{
		if (left > right)
		{
			return nullptr;
		}

		TreeNode* root = new TreeNode(nums[left]);
		int edge = left + 1;
		for (; edge <= right; edge++)
		{
			if (nums[edge] > nums[left])
			{
				break;
			}
		}
		root->left = getRoot(nums, left + 1, edge - 1);
		root->right = getRoot(nums, edge, right);
		return root;
	}
};

#pragma endregion

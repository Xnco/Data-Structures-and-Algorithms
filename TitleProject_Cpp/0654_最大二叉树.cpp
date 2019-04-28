
#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 654_最大二叉树
/*
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。
Example 1:
输入: [3,2,1,6,0,5]
输入: 返回下面这棵树的根节点：
	  6
	/   \
   3     5
	\    /
	 2  0
	   \
		1
注意:
给定的数组的大小在 [1, 1000] 之间。
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
	// 76ms(88.8%), 28.9MB(77.59%)
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return getRoot(nums, 0, nums.size() - 1);
	}

	TreeNode* getRoot(vector<int> & nums, int left, int right)
	{
		if (left > right)
		{
			return nullptr;
		}

		// 先找出范围内的最大值下标
		int maxIndex = left;
		for (size_t i = left + 1; i <= right; i++)
		{
			if (nums[maxIndex] < nums[i])
			{
				maxIndex = i;
			}
		}

		TreeNode* root = new TreeNode(nums[maxIndex]);
		root->left = getRoot(nums, left, maxIndex - 1);
		root->right = getRoot(nums, maxIndex + 1, right);
		return root;
	}
};
#pragma endregion

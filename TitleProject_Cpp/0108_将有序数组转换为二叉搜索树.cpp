
#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;
#include <math.h>

using namespace std;

#pragma region 108_将有序数组转换为二叉搜索树
/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
	  0
	 / \
   -3   9
   /   /
 -10  5
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
	// 384ms(5.14%), 361.6MB(5%)
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		return CreateRoot(left, right, nums);
	}

	TreeNode* CreateRoot(int left, int right, vector<int> list)
	{
		if (left > right) return nullptr;
		int mid = left + (right - left) / 2; // 除2改成右移1位(>>1)，会和面试官更配
		TreeNode* root = new TreeNode(list[mid]);
		root->left = CreateRoot(left, mid - 1, list);
		root->right = CreateRoot(mid + 1, right, list);
		return root;
	}
};

#pragma endregion
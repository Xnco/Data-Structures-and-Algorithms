#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 653_两数之和 IV - 输入 BST
/*
给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
案例 1:
输入:
	5
   / \
  3   6
 / \   \
2   4   7
Target = 9
输出: True
案例 2:
输入:
	5
   / \
  3   6
 / \   \
2   4   7
Target = 28
输出: False
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
	// 一种用 map 记录键值对, 判断差值是否存在
	// 更慢了, 68ms(14.6ms), 29.4MB(12.36%)
public:
	bool findTarget(TreeNode* root, int k) {
		map<int, int> res;
		getMap(root, res);

		for (auto item : res) {
			int target = k - item.first;
			if (res.find(target) != res.end())
			{
				if (target == item.first)
				{
					return item.second > 1;
				}
				return true;
			}
		}
		return false;
	}

	void getMap(TreeNode* root, map<int, int>& res)
	{
		if (root == nullptr) return;
		getMap(root->left, res);
		if (res.find(root->val) == res.end())
		{
			res[root->val] = 1;
		}
		else
		{
			res[root->val]++;
		}
		getMap(root->right, res);
	}

	// 一种中序遍历得到有序数组, 然后双指针
	// 44ms(98.4%), 24.7MB(100%)
	bool findTarget2(TreeNode* root, int k) {
		vector<int> res;
		getVec(root, res);

		int left = 0;
		int right = res.size() - 1;
		while (left < right)
		{
			int num = res[left] + res[right];
			if (num < k)
			{
				left++;
			}
			else if (num > k)
			{
				right--;
			}
			else {
				return true;
			}
		}
		return false;
	}

	void getVec(TreeNode* root, vector<int>& res)
	{
		if (root == nullptr) return;
		getVec(root->left, res);
		res.push_back(root->val);
		getVec(root->right, res);
	}
};
#pragma endregion

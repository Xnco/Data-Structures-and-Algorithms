#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;

using namespace std;

#pragma region 113_路径总和II
/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。
示例:
给定如下二叉树，以及目标和 sum = 22，

			  5
			 / \
			4   8
		   /   / \
		  11  13  4
		 /  \    / \
		7    2  5   1
返回:
[
   [5,4,11,2],
   [5,8,4,5]
]
*/


 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
// dfs, 40ms(23%), 38.4MB
// -> cur换成引用类型后16ms(击败100%), 19.7MB(击败93%)
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> cur;
		dfs(root, sum, cur, result);
		return result;
	}

	void dfs(TreeNode* root, int sum, vector<int>& cur, vector<vector<int>>& result)
	{
		if (root == nullptr) return;
		sum -= root->val;
		cur.push_back(root->val);
		if (root->right == nullptr && root->left == nullptr)
		{
			if (sum == 0)
			{
				result.push_back(cur);
			}
		}
		dfs(root->left, sum, cur, result);
		dfs(root->right, sum, cur, result);
		cur.pop_back();
	}
};
#pragma endregion
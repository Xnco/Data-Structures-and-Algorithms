
#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;

using namespace std;

#pragma region 102_二叉树的层次遍历
/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
例如:
给定二叉树: [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// 力扣 - 24ms(击败4.3%), 13.7MB  ===  Leetcode - 8ms 击败100%??? 13.8MB
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == nullptr)
		{
			return result;
		}
		
		vector<TreeNode*> cur;
		cur.push_back(root);

		vector<int> curNum;
		vector<TreeNode*> next;
		while (true)
		{
			for (size_t i = 0; i < cur.size(); i++)
			{
				curNum.push_back(cur[i]->val);
				
				if (cur[i]->left != nullptr)
				{
					next.push_back(cur[i]->left);
				}
				if (cur[i]->right != nullptr)
				{
					next.push_back(cur[i]->right);
				}
			}
			result.push_back(curNum);
			if (next.size() == 0)
			{
				return result;
			}
			curNum.clear();
			cur = next;
			vector<TreeNode*> temp;
			next = temp;
		}
	}
};
#pragma endregion
#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;

using namespace std;

#pragma region 437_路径总和 III - Path Sum III
/*
给定一个二叉树，它的每个结点都存放着一个整数值。
找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
示例：
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
	  10
	 /  \
	5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1
返回 3。和等于 8 的路径有:
1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11
*/


 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
 // 拿113的路径总数II 过来改点细节做的双递归, 应该可以更简便的
 // 40ms(18%), 15.3MB(70%)
class Solution {
	int result;
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr)
		{
			return 0;
		}
		hasPathSum(root, sum, result);
		pathSum(root->left, sum);
		pathSum(root->right, sum);
		return result;
	}

	bool hasPathSum(TreeNode* root, int sum, int& result) {
		if (root == nullptr) return false;
		sum -= root->val;
		if (sum == 0)
		{
			result++;
		}
		return hasPathSum(root->left, sum, result) || hasPathSum(root->right, sum, result);
	}
};

#pragma endregion
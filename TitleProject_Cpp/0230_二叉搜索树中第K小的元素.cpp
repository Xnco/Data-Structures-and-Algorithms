
#pragma region 230_二叉搜索树中第K小的元素
/*
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
示例 1:
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
示例 2:
输入: root = [5,3,6,2,4,null,null,1], k = 3
	   5
	  / \
	 3   6
	/ \
   2   4
  /
 1
输出: 3
进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
	// 迭代 - 中序遍历 - 找到第k个即可
	int kthSmallest(TreeNode* root, int k) {
		if (root == nullptr) return 0;

		stack<TreeNode*> stackNode;
		stackNode.push(root);
		while (!stackNode.empty())
		{
			TreeNode* temp = stackNode.top();
			stackNode.pop();

			if (temp->right != nullptr)
			{
				stackNode.push(temp->right);
			}

			stackNode.push(temp);
			if (temp->left != nullptr)
			{
				stackNode.push(temp->left);
			}
			else
			{
				break;
			}
		}
		while (k != 1)
		{
			stackNode.pop();
			--k;
		}
		TreeNode* temp = stackNode.top();
		return temp->val;
	}

	// 递归中序遍历 
	//Runtime: 20 ms, faster than 81.73 % of C++ online submissions for Kth Smallest Element in a BST.
	//Memory Usage : 21.4 MB, less than 98.33 % of C++ online submissions for Kth Smallest Element in a BST.
	int kthSmallest(TreeNode* root, int k) {
		if (root == nullptr) return 0;
		int res;
		mid(root, k, res);
		return res;
	}

	void mid(TreeNode* root, int& k, int& res) {
		if (root == nullptr)
		{
			return;
		}
		mid(root->left, k, res);
		if (--k == 0)
		{
			res = root->val;
		}
		mid(root->right, k, res);
	}

};
#pragma endregion

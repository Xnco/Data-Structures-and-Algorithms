
#pragma region 513_找树左下角的值
/*
给定一个二叉树，在树的最后一行找到最左边的值。
示例 1:
输入:
	2
   / \
  1   3
输出:
1
示例 2:
输入:
		1
	   / \
	  2   3
	 /   / \
	4   5   6
	   /
	  7
输出:
7
注意: 您可以假设树（即给定的根节点）不为 NULL。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-bottom-left-tree-value
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
	// bfs - 左->右 - 迭代
	//Runtime: 16 ms, faster than 67.36% of C++ online submissions for Find Bottom Left Tree Value.
	//Memory Usage : 20.8 MB, less than 84.06 % of C++ online submissions for Find Bottom Left Tree Value.
	int findBottomLeftValue(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*> layer;
		layer.push(root);
		int res = 0;
		while (!layer.empty())
		{
			int count = layer.size();
			res = layer.front()->val; // 每一层的最左边的值
			for (int i = 0; i < count; ++i)
			{
				TreeNode* node = layer.front();
				layer.pop();
				if (node->left != nullptr)
				{
					layer.push(node->left);
				}
				if (node->right != nullptr)
				{
					layer.push(node->right);
				}
			}
		}
		return res;
	}
};
#pragma endregion

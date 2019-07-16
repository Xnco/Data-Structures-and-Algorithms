
#pragma region 199_二叉树的右视图
/*
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
示例:
输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
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
	// bfs 
	// 0ms(100%), 9.4MB(90.26%)
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
		{
			return res;
		}
		vector<TreeNode*> layer;
		layer.push_back(root);

		while (!layer.empty())
		{
			vector<TreeNode*> newLayer;
			res.push_back(layer[layer.size() - 1]->val);
			for (int i = 0; i < layer.size(); i++)
			{
				if (layer[i]->left != nullptr)
				{
					newLayer.push_back(layer[i]->left);
				}
				if (layer[i]->right != nullptr)
				{
					newLayer.push_back(layer[i]->right);
				}
			}
			layer = newLayer;
		}
		return res;
	}

	// 用队列做 
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		queue<TreeNode*> layer;
		layer.push(root);

		while (!layer.empty())
		{
			for (int i = layer.size() - 1; i >= 0; --i)
			{
				TreeNode* temp = layer.front();
				layer.pop();
				if (i == 0)
					res.push_back(temp->val);
				if (temp->left)
					layer.push(temp->left);
				if (temp->right)
					layer.push(temp->right);
			}

		}
		return res;
	}
};
#pragma endregion


#pragma region 783_二叉搜索树结点最小距离
/*
给定一个二叉搜索树的根结点 root, 返回树中任意两节点的差的最小值。
示例：
输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树结点对象(TreeNode object)，而不是数组。
给定的树 [4,2,6,1,3,null,null] 可表示为下图:

		  4
		/   \
	  2      6
	 / \
	1   3

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
注意：
二叉树的大小范围在 2 到 100。
二叉树总是有效的，每个节点的值都是整数，且不重复。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
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
	// 先中序遍历得到一个 vector<int>, 再两两对比差值即可
	int minDiffInBST(TreeNode* root) {
		vector<int> res;
		getVec(root, res);

		int num = abs(res[0] - res[1]);
		for (size_t i = 1; i < res.size() - 1; i++)
		{
			int n = abs(res[i] - res[i + 1]);
			if (n < num)
			{
				num = n;
			}
		}
		return num;
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

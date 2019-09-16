
#pragma region 655_输出二叉树
/*
在一个 m*n 的二维字符串数组中输出二叉树，并遵守以下规则：

行数 m 应当等于给定二叉树的高度。
列数 n 应当总是奇数。
根节点的值（以字符串格式给出）应当放在可放置的第一行正中间。根节点所在的行与列会将剩余空间划分为两部分（左下部分和右下部分）。你应该将左子树输出在左下部分，右子树输出在右下部分。左下和右下部分应当有相同的大小。即使一个子树为空而另一个非空，你不需要为空的子树输出任何东西，但仍需要为另一个子树留出足够的空间。然而，如果两个子树都为空则不需要为它们留出任何空间。
每个未使用的空间应包含一个空的字符串""。
使用相同的规则输出子树。
示例 1:

输入:
	 1
	/
   2
输出:
[["", "1", ""],
 ["2", "", ""]]
示例 2:

输入:
	 1
	/ \
   2   3
	\
	 4
输出:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
示例 3:

输入:
	  1
	 / \
	2   5
   /
  3
 /
4
输出:
[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
注意: 二叉树的高度在范围 [1, 10] 中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/print-binary-tree
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
	//Runtime: 4 ms, faster than 70.19% of C++ online submissions for Print Binary Tree.
	//Memory Usage : 9.4 MB, less than 100.00 % of C++ online submissions for Print Binary Tree.
	vector<vector<string>> printTree(TreeNode* root) {
		// 得到高度
		int height = GetTreeHigh(root);

		// 根据高度得出数组Count
		int width = pow(2, height) - 1;

		// 初始化res
		vector<vector<string>> res(height, vector<string>(width, ""));

		// 再遍历一次赋值
		SetValueLine(root, res, 0, 0, width - 1);
		return res;
	}

	int GetTreeHigh(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		return max(GetTreeHigh(root->left), GetTreeHigh(root->right)) + 1;
	}

	void SetValueLine(TreeNode* root, vector<vector<string>>& res, int curLine, int left, int right)
	{
		if (root == NULL || left > right)
		{
			return;
		}
		int center = (left + right) / 2;
		res[curLine][center] = to_string(root->val);
		SetValueLine(root->left, res, curLine + 1, left, center - 1);
		SetValueLine(root->right, res, curLine + 1, center + 1, right);
	}
};
#pragma endregion

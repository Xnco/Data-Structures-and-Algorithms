
#pragma region 508_出现次数最多的子树元素和
/*
给出二叉树的根，找出出现次数最多的子树元素和。一个结点的子树元素和定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
然后求出出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的元素（不限顺序）。
示例 1
输入:

  5
 /  \
2   -3
返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。
示例 2
输入:

  5
 /  \
2   -5
返回 [2]，只有 2 出现两次，-5 只出现 1 次。
提示： 假设任意子树元素和均可以用 32 位有符号整数表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/most-frequent-subtree-sum
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
	//Runtime: 16 ms, faster than 96.64% of C++ online submissions for Most Frequent Subtree Sum.
	//Memory Usage : 23.5 MB, less than 66.67 % of C++ online submissions for Most Frequent Subtree Sum.
	vector<int> findFrequentTreeSum(TreeNode* root) {
		unordered_map<int, int> m;
		dfs(root, m);
		int max = 0;
		for (const auto item : m)
		{
			if (item.second > max)
			{
				max = item.second;
			}
		}
		vector<int> res;
		for (const auto item : m)
		{
			if (item.second == max)
			{
				res.push_back(item.first);
			}
		}
		return res;
	}

	int dfs(TreeNode* root, unordered_map<int, int>& m)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int left = dfs(root->left, m);
		int right = dfs(root->right, m);
		int value = root->val + left + right;
		if (m.find(value) == m.end())
		{
			m[value] = 1;
		}
		else
		{
			m[value]++;
		}
		return value;
	}
};
#pragma endregion

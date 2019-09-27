
#pragma region 652_寻找重复的子树
/*
给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
两棵树重复是指它们具有相同的结构以及相同的结点值。
示例 1：

		1
	   / \
	  2   3
	 /   / \
	4   2   4
	   /
	  4
下面是两个重复的子树：
	  2
	 /
	4
和

	4
因此，你需要以列表的形式返回上述重复子树的根结点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-duplicate-subtrees
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
	// 子树不可能和root重复, 所以只要判断层次遍历之后的树是否和我重复即可

	// 将每个子树的路径都存下来, 通过map判断是否重复
	// 空间换时间
	//Runtime : 44 ms, faster than 49.08 % of C++ online submissions for Find Duplicate Subtrees.
	//Memory Usage : 102.4 MB, less than 33.33 % of C++ online submissions for Find Duplicate Subtrees.
	struct MyTreeNode {
	public:
		TreeNode* root;
		int count;
		MyTreeNode() {}
		MyTreeNode(TreeNode* r, int n)
		{
			root = r;
			count = n;
		}
	};

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		unordered_map<string, MyTreeNode> m;
		vector<TreeNode*> res;
		dfs(root, m);

		for (auto& item : m)
		{
			if (item.second.count > 1)
			{
				res.push_back(item.second.root);
			}
		}
		return res;
	}

	string dfs(TreeNode* root, unordered_map<string, MyTreeNode>& m)
	{
		if (root == nullptr)
		{
			return "";
		}

		string myPath = to_string(root->val);
		string leftPath = myPath + "-" + dfs(root->left, m);
		string rightPath = myPath + "-" + dfs(root->right, m);
		if (leftPath != "" || rightPath != "")
		{
			myPath += "." + leftPath + "." + rightPath;
		}
		if (m.find(myPath) == m.end())
		{
			m[myPath] = MyTreeNode(root, 1);
		}
		else
		{
			++m[myPath].count;
		}
		return myPath;
	}
};
#pragma endregion

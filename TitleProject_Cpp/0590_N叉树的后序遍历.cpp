
#pragma region 590_N叉树的后序遍历
/*
给定一个 N 叉树，返回其节点值的后序遍历。
例如，给定一个 3叉树 :
返回其后序遍历: [5,6,3,2,4,1].
说明: 递归法很简单，你可以使用迭代法完成此题吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:

	// 递归
	//Runtime : 148 ms, faster than 84.33 % of C++ online submissions for N - ary Tree Postorder Traversal.
	//Memory Usage : 32.4 MB, less than 86.01 % of C++ online submissions for N - ary Tree Postorder Traversal.
	vector<int> postorder(Node* root) {
		vector<int> res;
		bfs(root, res);
		return res;
	}

	void bfs(Node* root, vector<int>& res)
	{
		if (!root)
		{
			return;
		}

		for (int i = 0; i < root->children.size(); i++)
		{
			bfs(root->children[i], res);
		}

		res.push_back(root->val);
	}
};
#pragma endregion


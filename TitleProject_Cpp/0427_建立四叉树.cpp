
#pragma region 427_建立四叉树
/*
我们想要使用一棵四叉树来储存一个 N x N 的布尔值网络。网络中每一格的值只会是真或假。树的根结点代表整个网络。对于每个结点,
它将被分等成四个孩子结点直到这个区域内的值都是相同的.
每个结点还有另外两个布尔变量: isLeaf 和 val。isLeaf 当这个节点是一个叶子结点时为真。val 变量储存叶子结点所代表的区域的值。
你的任务是使用一个四叉树表示给定的网络。下面的例子将有助于你理解这个问题：
给定下面这个8 x 8 网络，我们将这样建立一个对应的四叉树：
由上文的定义，它能被这样分割：
对应的四叉树应该像下面这样，每个结点由一对 (isLeaf, val) 所代表.
对于非叶子结点，val 可以是任意的，所以使用 * 代替。
提示：
N 将小于 1000 且确保是 2 的整次幂。
如果你想了解更多关于四叉树的知识，你可以参考这个 wiki 页面。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-quad-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Definition for a QuadTree node.
class Node {
public:
	bool val;
	bool isLeaf;
	Node* topLeft;
	Node* topRight;
	Node* bottomLeft;
	Node* bottomRight;

	Node() {}

	Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		val = _val;
		isLeaf = _isLeaf;
		topLeft = _topLeft;
		topRight = _topRight;
		bottomLeft = _bottomLeft;
		bottomRight = _bottomRight;
	}
};

class Solution {
public:
	// 递归 - 四合一
	//Runtime: 124 ms, faster than 88.91% of C++ online submissions for Construct Quad Tree.
	//Memory Usage : 39 MB, less than 58.33 % of C++ online submissions for Construct Quad Tree.
	Node* construct(vector<vector<int>>& grid) {
		return dfs(grid, 0, grid.size() - 1, 0, grid[0].size() - 1);
	}

	Node* dfs(vector<vector<int>>& grid, int left, int right, int top, int bottom)
	{
		Node* node = new Node(true, true, NULL, NULL, NULL, NULL);
		if (bottom - top < 1)
		{
			node->val = grid[top][left] == 1;
			return node;
		}

		Node* tl = dfs(grid, left, (right + left) / 2, top, (top + bottom) / 2);
		Node* tr = dfs(grid, (right + left) / 2 + 1, right, top, (top + bottom) / 2);
		Node* bl = dfs(grid, left, (right + left) / 2, (bottom + top) / 2 + 1, bottom);
		Node* br = dfs(grid, (right + left) / 2 + 1, right, (bottom + top) / 2 + 1, bottom);
		// All True or All False
		if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf &&
			tl->val == tr->val && tl->val == bl->val && tl->val == br->val)
		{
			node->val = tl->val;
		}
		else
		{
			node->isLeaf = false;
			node->topLeft = tl;
			node->topRight = tr;
			node->bottomLeft = bl;
			node->bottomRight = br;
		}
		return node;
	}
};
#pragma endregion

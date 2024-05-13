
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

#pragma region 427_建立四叉树
/*
https://leetcode.cn/problems/construct-quad-tree/description/
给你一个 n * n 矩阵 grid ，矩阵由若干 0 和 1 组成。请你用四叉树表示该矩阵 grid 。

你需要返回能表示矩阵 grid 的 四叉树 的根结点。

四叉树数据结构中，每个内部节点只有四个子节点。此外，每个节点都有两个属性：

val：储存叶子结点所代表的区域的值。1 对应 True，0 对应 False。注意，当 isLeaf 为 False 时，你可以把 True 或者 False 赋值给节点，两种值都会被判题机制 接受 。
isLeaf: 当这个节点是一个叶子结点时为 True，如果它有 4 个子节点则为 False 。
class Node {
	public boolean val;
	public boolean isLeaf;
	public Node topLeft;
	public Node topRight;
	public Node bottomLeft;
	public Node bottomRight;
}
我们可以按以下步骤为二维区域构建四叉树：

如果当前网格的值相同（即，全为 0 或者全为 1），将 isLeaf 设为 True ，将 val 设为网格相应的值，并将四个子节点都设为 Null 然后停止。
如果当前网格的值不同，将 isLeaf 设为 False， 将 val 设为任意值，然后如下图所示，将当前网格划分为四个子网格。
使用适当的子网格递归每个子节点。

示例 1：
输入：grid = [[0,1],[1,0]]
输出：[[0,1],[1,0],[1,1],[1,1],[1,0]]
解释：此示例的解释如下：
请注意，在下面四叉树的图示中，0 表示 false，1 表示 True 。

提示
1. n == grid.length == grid[i].length
2. n == 2x 其中 0 <= x <= 6
*/

class Solution {
public:

	/*
	// Definition for a QuadTree node.
	*/
	class Node {
	public:
		bool val;
		bool isLeaf;
		Node* topLeft;
		Node* topRight;
		Node* bottomLeft;
		Node* bottomRight;

		Node() {
			val = false;
			isLeaf = false;
			topLeft = NULL;
			topRight = NULL;
			bottomLeft = NULL;
			bottomRight = NULL;
		}

		Node(bool _val, bool _isLeaf) {
			val = _val;
			isLeaf = _isLeaf;
			topLeft = NULL;
			topRight = NULL;
			bottomLeft = NULL;
			bottomRight = NULL;
		}

		Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
			val = _val;
			isLeaf = _isLeaf;
			topLeft = _topLeft;
			topRight = _topRight;
			bottomLeft = _bottomLeft;
			bottomRight = _bottomRight;
		}
	};

	Node* construct(vector<vector<int>>& grid) {
		Node* tNode = ConstructRoot(grid, 0, grid.size(), 0, grid.size());
		return tNode;
	}

	Node* ConstructRoot(vector<vector<int>>& grid, int left, int right, int top, int bottom)
	{
		if (right - left == 1)
		{
			Node* tNode = new Node;
			tNode->isLeaf = true;
			tNode->val = grid[left][top];
			return tNode;
		}
		else
		{
			Node* topLeftNode = ConstructRoot(grid, left, left + (right - left) / 2, top, top + (bottom - top) / 2);
			Node* topRightNode = ConstructRoot(grid, left, left + (right - left) / 2, top + (bottom - top) / 2, bottom);
			Node* bottomLeftNode = ConstructRoot(grid, left + (right - left) / 2, right, top, top + (bottom - top) / 2);
			Node* bottomRightNode = ConstructRoot(grid, left + (right - left) / 2, right, top + (bottom - top) / 2, bottom);
			if (topLeftNode->isLeaf
				&& topRightNode->isLeaf
				&& bottomLeftNode->isLeaf
				&& bottomRightNode->isLeaf
				&& topLeftNode->val == topRightNode->val
				&& bottomLeftNode->val == bottomRightNode->val
				&& topLeftNode->val == bottomLeftNode->val)
			{
				Node* tNode = new Node;
				tNode->isLeaf = true;
				tNode->val = topLeftNode->val;
				return tNode;
			}
			else
			{
				Node* tNode = new Node;
				tNode->isLeaf = false;
				tNode->topLeft = topLeftNode;
				tNode->topRight = topRightNode;
				tNode->bottomLeft = bottomLeftNode;
				tNode->bottomRight = bottomRightNode;
				return tNode;
			}
		}
	}
};

#pragma endregion

int main()
{
	Solution s;
	vector<vector<int>> grid;
	//grid.push_back({ 0, 1 });
	//grid.push_back({ 1, 0 });
	grid.push_back({ 1,1,1,1,0,0,0,0 });
	grid.push_back({ 1,1,1,1,0,0,0,0 });
	grid.push_back({ 1,1,1,1,1,1,1,1 });
	grid.push_back({ 1,1,1,1,1,1,1,1 });
	grid.push_back({ 1,1,1,1,0,0,0,0 });
	grid.push_back({ 1,1,1,1,0,0,0,0 });
	grid.push_back({ 1,1,1,1,0,0,0,0 });
	grid.push_back({ 1,1,1,1,0,0,0,0 });

	s.construct(grid);
}
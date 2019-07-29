
#pragma region 797_所有可能的路径
/*
给一个有 n 个结点的有向无环图，找到所有从 0 到 n-1 的路径并输出（不要求按顺序）
二维数组的第 i 个数组中的单元都表示有向图中 i 号结点所能到达的下一些结点, 空就是没有下一个结点了。
（译者注：有向图是有方向的，即规定了a→b你就不能从b→a）
示例:
输入: [[1,2], [3], [3], []]
输出: [[0,1,3],[0,2,3]]
解释: 图是这样的:
0--->1
|    |
v    v
2--->3
这有两条路: 0 -> 1 -> 3 和 0 -> 2 -> 3.
提示:
结点的数量会在范围 [2, 15] 内。
你可以把路径以任意顺序输出，但在路径内的结点的顺序必须保证。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-paths-from-source-to-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 回溯, 会有重复
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> res;
		vector<int> path;
		int end = graph.size() - 1; // 终点
		find(path, graph, 0, end, res);
		return res;
	}

	void find(vector<int>& path, vector<vector<int>>& graph, int curNode, int end, vector<vector<int>>& res)
	{
		path.push_back(curNode);
		if (curNode == end)
		{
			res.push_back(path);
			return;
		}

		for (int i = 0; i < graph[curNode].size(); i++)
		{
			find(path, graph, graph[curNode][i], end, res);
		}
		path.pop_back();
	}
};
#pragma endregion

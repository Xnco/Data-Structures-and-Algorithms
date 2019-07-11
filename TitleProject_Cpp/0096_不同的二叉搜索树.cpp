
#pragma region 96_不同的二叉搜索树
/*
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
示例:
输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
	\       /     /      / \      \
	 3     2     1      1   3      2
	/     /       \                 \
   2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 440(5.81), 8.1MB(93.89%) 时间换空间, 没有缓存, 但很慢
	int numTrees(int n) {
		switch (n)
		{
		case -1:
		case 0: return 1;
		case 1: return 2;
		case 2: return 5;
		default: break;
		}

		int res = 0;
		if (left > right)
		{
			return 1;
		}

		for (size_t i = 1; i <= n; i++)
		{
			res += numTrees(i - 1) * numTrees(n - i);
		}
		return res;
	}


	// 加缓存
	// 4ms(68.88%), 8.4MB(15.83%)
	int numTrees(int n)
	{
		vector<int> res(n + 1);
		if (n == 0)
		{
			return 1;
		}

		res[0] = 1;
		for (size_t i = 1; i <= n; i++)
		{
			res[i] = 0;
			for (size_t j = 0; j < i; j++)
			{
				res[i] += res[j] * res[i - j - 1];
			}
		}
		return res[n];
	}
};
#pragma endregion

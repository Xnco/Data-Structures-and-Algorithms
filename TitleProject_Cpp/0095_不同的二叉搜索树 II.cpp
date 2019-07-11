
#pragma region 95_不同的二叉搜索树 II
/*
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
示例:
输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
	\       /     /      / \      \
	 3     2     1      1   3      2
	/     /       \                 \
   2     1         2                 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii
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
	// 24ms(37.22%), 17.2MB(37.39%)
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) return vector<TreeNode*>();
		return Func1(1, n);
	}

	vector<TreeNode*> Func1(int left, int right)
	{
		vector<TreeNode*> res;
		if (left > right)
		{
			res.push_back(NULL);
			return res;
		}

		for (size_t i = left; i <= right; i++)
		{
			// 左边的可能性
			vector<TreeNode*> leftList = Func1(left, i - 1);
			// 右边的可能性
			vector<TreeNode*> rightList = Func1(i + 1, right);

			for (size_t j = 0; j < leftList.size(); j++)
			{
				for (size_t k = 0; k < rightList.size(); k++)
				{
					TreeNode* temp = new TreeNode(i);
					temp->left = leftList[j];
					temp->right = rightList[k];
					res.push_back(temp);
				}
			}
		}
		return res;
	}
};
#pragma endregion

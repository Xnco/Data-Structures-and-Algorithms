
#pragma region 572_另一个树的子树
/*
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

	 3
	/ \
   4   5
  / \
 1   2
给定的树 t：

   4
  / \
 1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

示例 2:
给定的树 s：

	 3
	/ \
   4   5
  / \
 1   2
	/
   0
给定的树 t：

   4
  / \
 1   2
返回 false。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subtree-of-another-tree
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
	// 暴力
	//Runtime: 40 ms, faster than 20.65% of C++ online submissions for Subtree of Another Tree.
	//Memory Usage : 29.7 MB, less than 6.25 % of C++ online submissions for Subtree of Another Tree.
	bool isSubtree(TreeNode* s, TreeNode* t) {
		queue<TreeNode*> q;
		q.push(s);
		while (q.size() != 0)
		{
			TreeNode* temp = q.front();
			if (Equal(temp, t)) return true;
			if (temp->left != nullptr) q.push(temp->left);
			if (temp->right != nullptr) q.push(temp->right);
			q.pop();
		}
		return false;
	}

	bool Equal(TreeNode* root, TreeNode* t)
	{
		if (root == nullptr && t == nullptr) return true;

		if (root == nullptr || t == nullptr) return false;

		if (root->val == t->val)
		{
			return Equal(root->left, t->left) && Equal(root->right, t->right);
		}
		return false;
	}

	// KMP 
	//Runtime: 44 ms, faster than 14.93% of C++ online submissions for Subtree of Another Tree.
	//Memory Usage : 30.4 MB, less than 6.25 % of C++ online submissions for Subtree of Another Tree.
	int maxValue, lNullValue, rNullValue;
	bool isSubtree2(TreeNode* s, TreeNode* t) {
		maxValue = INT_MIN;
		GetMaxValeu(s);
		GetMaxValeu(t);

		lNullValue = maxValue + 1;
		rNullValue = maxValue + 2;

		vector<int> sList, tList;
		GetOrder(s, sList);
		GetOrder(t, tList);

		return KMP(sList, tList);
	}

	void GetMaxValeu(TreeNode* root)
	{
		if (!root) return;
		maxValue = max(maxValue, root->val);
		GetMaxValeu(root->left);
		GetMaxValeu(root->right);
	}

	void GetOrder(TreeNode* root, vector<int>& list)
	{
		if (!root) return;

		list.push_back(root->val);
		if (root->left)
		{
			GetOrder(root->left, list);
		}
		else
		{
			list.push_back(lNullValue);
		}

		if (root->right)
		{
			GetOrder(root->right, list);
		}
		else
		{
			list.push_back(rNullValue);
		}
	}

	// 判断slist是否包含tlist - 有待改进 - 比暴力还慢了4ms
	bool KMP2(vector<int>& sList, vector<int>& tList)
	{
		for (int i = 0; i < sList.size(); ++i)
		{
			if (sList[i] == tList[0])
			{
				bool bIsEqual = true;
				for (int j = 0; j < tList.size(); ++j)
				{
					if (sList[i + j] != tList[j])
					{
						bIsEqual = false;
						break;
					}
				}

				if (bIsEqual)
				{
					return true;
				}
			}
		}
		return false;
	}

	//Runtime: 36 ms, faster than 29.57% of C++ online submissions for Subtree of Another Tree.
	//Memory Usage : 30.6 MB, less than 6.25 % of C++ online submissions for Subtree of Another Tree.
	bool KMP(vector<int>& sList, vector<int>& tList)
	{
		int sLen = sList.size(), tLen = tList.size();
		vector <int> fail(tList.size(), -1);
		for (int i = 1, j = -1; i < tLen; ++i)
		{
			while (j != -1 && tList[i] != tList[j + 1])
			{
				j = fail[j];
			}
			if (tList[i] == tList[j + 1])
			{
				++j;
			}
			fail[i] = j;
		}
		for (int i = 0, j = -1; i < sLen; ++i)
		{
			while (j != -1 && sList[i] != tList[j + 1])
			{
				j = fail[j];
			}
			if (sList[i] == tList[j + 1])
			{
				++j;
			}
			if (j == tLen - 1)
			{
				return true;
			}
		}
		return false;
	}
};
#pragma endregion

int main()
{
	/*
		3
		/ \
		4   5
		/ \
		1   2

		4
		/ \
		1   2
	*/
	TreeNode* t1 = new TreeNode(3);
	t1->left = new TreeNode(4);
	t1->right = new TreeNode(5);
	t1->left->left = new TreeNode(1);
	t1->left->right = new TreeNode(2);
	TreeNode* t2 = new TreeNode(4);
	t2->left = new TreeNode(1);
	t2->right = new TreeNode(2);

	Solution s;
	s.isSubtree2(t1, t2);
}
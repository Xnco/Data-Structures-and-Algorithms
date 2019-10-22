
#pragma region 449_序列化和反序列化二叉搜索树
/*
序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，
或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
设计一个算法来序列化和反序列化二叉搜索树。 对序列化/反序列化算法的工作方式没有限制。
您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
编码的字符串应尽可能紧凑。
注意：不要使用类成员/全局/静态变量来存储状态。 你的序列化和反序列化算法应该是无状态的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/serialize-and-deserialize-bst
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
class Codec {
public:
	// Runtime: 32 ms, faster than 61.08% of C++ online submissions for Serialize and Deserialize BST.
	// Memory Usage : 26.6 MB, less than 26.92 % of C++ online submissions for Serializeand Deserialize BST.
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res = "";
		foreSerialize(root, res);
		return res;
	}

	// 前序遍历 序列化
	void foreSerialize(TreeNode* root, string& res)
	{
		if (root == NULL)
		{
			res += "#_";
			return;
		}
		res += to_string(root->val) + "_";
		foreSerialize(root->left, res);
		foreSerialize(root->right, res);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		vector<string> list = split(data, '_');
		int index = 0;
		TreeNode* res = ForeDeserizlize(list, index);
		return res;
	}

	TreeNode* ForeDeserizlize(vector<string>& str, int& index)
	{
		if (str[index] == "#")
		{
			++index;
			return NULL;
		}
		TreeNode* root = new TreeNode(stoi(str[index++]));
		root->left = ForeDeserizlize(str, index);
		root->right = ForeDeserizlize(str, index);
		return root;
	}

	vector<string> split(const string& str, char delim) {
		vector<string> list;
		int begin = 0;
		while (begin < str.size())
		{
			int sIndex = str.find(delim, begin);
			if (sIndex != str.npos)
			{
				list.push_back(str.substr(begin, sIndex - begin));
				begin = sIndex + 1;
			}
			else
			{
				list.push_back(str.substr(begin));
				break;
			}
		}

		return list;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
#pragma endregion

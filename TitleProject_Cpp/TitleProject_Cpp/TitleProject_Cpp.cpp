// TitleProject_Cpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <unordered_set>

using namespace std;

#pragma region 0_
/*

*/
#pragma endregion

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

	}

	vector<string>& split(const string& str, char delim) {
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

#pragma region 932_漂亮数组
/*
对于某些固定的 N，如果数组 A 是整数 1, 2, ..., N 组成的排列，使得：
对于每个 i < j，都不存在 k 满足 i < k < j 使得 A[k] * 2 = A[i] + A[j]。
那么数组 A 是漂亮数组。
给定 N，返回任意漂亮数组 A（保证存在一个）。

示例 1：
输入：4
输出：[2,1,4,3]

示例 2：
输入：5
输出：[3,1,2,5,4]

提示：
1 <= N <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/beautiful-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
class Solution {
public:
	// 暴力
	vector<int> beautifulArray(int N) {
		
	}
};
*/
#pragma endregion

int main()
{

}
	

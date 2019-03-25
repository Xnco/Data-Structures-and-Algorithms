﻿// TitleProject_Cpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h";
#include <iostream>;
#include <vector>;
#include <sstream>;
#include <stack>;

using namespace std;

#pragma region 0_
/*
	
*/
#pragma endregion

#pragma region 106_从中序与后序遍历序列构造二叉树
/*
根据一棵树的中序遍历与后序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
例如，给出
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：
	3
   / \
  9  20
	/  \
   15   7
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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int p_len = postorder.size();

		TreeNode root(postorder[p_len - 1]);
		TreeNode* root_p = &root;

		// postorder的最后一个注定是root, root在inorder的位置将树分为左右两边, 二分
		
	}
};
#pragma endregion

#pragma region 204_计数质数
/*
统计所有小于非负整数 n 的质数的数量。
示例:
输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/
class Solution {
public:
	// -- 暴力 -- 超时
	int countPrimes(int n) {
		int count = 0;
		for (size_t i = 0; i < n; i++)
		{

			if (isPrimes(i))
			{
				count++;
			}
		}
		return count;
	}

	bool isPrimes(int num)
	{
		if (num == 0 || num == 1)
		{
			return false;
		}
		int n = sqrt(num);
		for (size_t i = 2; i <= n; i++)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
		return true;
	}

	// 厄拉多塞筛法
	int countPrimes2(int n)
	{
		if (n == 0 || n == 1)
		{
			return 0;
		}
		vector<bool> arr(n + 1);
		// 0, 1 不是质数
		arr[0] = 1;
		arr[1] = 1;
		int count = 0;
		for (size_t i = 2; i < n; i++)
		{
			if (arr[i] == 0)
			{
				count++;
				// 出现一个质数, 他的倍数都不是质数
				for (int j = i * i; j < n; j += i)
				{
					arr[j] = 1;
				}
			}
		}
		return count;
	}
};

#define MAXN 100

// 数组
bool flag[MAXN] = { 0 };    //将标识初始化为true
void erat(int maxn)
{
	flag[0] = 0;            //0不是質数
	flag[1] = 0;            //1不是質数
	for (int i = 2; i <= maxn; ++i)
	{
		/*当i为質数时，i的所有倍数都不是質数*/
		if (flag[i])
		{
			for (int j = i * i; j <= maxn; j += i)
			{
				flag[j] = 0;
			}
		}
	}
}
#pragma endregion

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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


int main()
{

}

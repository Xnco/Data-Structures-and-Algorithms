// TitleProject_Cpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

#pragma region 179_最大数
/*
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
示例 1:
输入: [10,2]
输出: 210
示例 2:
输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
*/

class Solution {
public:
	string largestNumber(vector<int>& nums) {

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
		vector<bool> arr(n + 1, 0);
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

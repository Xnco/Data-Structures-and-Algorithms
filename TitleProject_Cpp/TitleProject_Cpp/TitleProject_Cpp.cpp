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

#pragma region 858_镜面反射
/*
有一个特殊的正方形房间，每面墙上都有一面镜子。除西南角以外，每个角落都放有一个接受器，编号为 0， 1，以及 2。
正方形房间的墙壁长度为 p，一束激光从西南角射出，首先会与东墙相遇，入射点到接收器 0 的距离为 q 。
返回光线最先遇到的接收器的编号（保证光线最终会遇到一个接收器）。

示例：
输入： p = 2, q = 1
输出： 2
解释： 这条光线在第一次被反射回左边的墙时就遇到了接收器 2 。

提示：
1 <= p <= 1000
0 <= q <= p

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/mirror-reflection
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
class Solution {
public:
	int mirrorReflection(int p, int q) {

	}
};*/
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
	

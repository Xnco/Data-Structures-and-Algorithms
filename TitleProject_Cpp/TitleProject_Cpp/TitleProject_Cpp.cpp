// TitleProject_Cpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 0_
/*

*/
#pragma endregion

#pragma region 139_单词拆分
/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
说明：
拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 暴力 - 超时
	bool wordBreak(string s, vector<string>& wordDict) {
		return bfs(s, 0, wordDict);
	}

	bool bfs(string s, int begin, vector<string>& wordDict)
	{
		if (s.size() == begin)
		{
			// 最后一个了
			return true;
		}
		
		for (int count = 1; count <= s.size() - begin; count++)
		{
			if (find(wordDict.begin(), wordDict.end(), s.substr(begin, count)) != wordDict.end())
			{
				// 存在
				if (bfs(s, begin + count, wordDict) != 0)
				{
					return true;
				}
			}
		}
		return false;
	}

	// 方案2
	bool wordBreak(string s, vector<string>& wordDict)
	{

	}
};
#pragma endregion

int main()
{

}
	

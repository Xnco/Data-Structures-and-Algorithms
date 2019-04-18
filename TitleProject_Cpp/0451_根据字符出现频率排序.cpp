#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#pragma region 451_根据字符出现频率排序
/*
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
示例 1:
输入:
"tree"
输出:
"eert"
解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
示例 2:
输入:
"cccaaa"
输出:
"cccaaa"
解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
示例 3:
输入:
"Aabb"
输出:
"bbAa"
解释:
此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。
*/

class Solution {
	// 20ms(75%), 11MB(62%)
public:
	string frequencySort(string s) {
		string res;
		map<char, int> all;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (all.find(s[i]) == all.end())
			{
				all[s[i]] = 1;
			}
			else
			{
				all[s[i]]++;
			}
		}
		vector<pair<char, int>> vec;
		for (auto& item : all)
		{
			vec.push_back({ item.first, item.second });
		}
		sort(vec.begin(), vec.end(), [](pair<char, int> i1, pair<char, int> i2) {return i1.second > i2.second; });
		for (auto& item : vec)
		{
			res += string(item.second, item.first);
		}
		return res;
	}
};
#pragma endregion
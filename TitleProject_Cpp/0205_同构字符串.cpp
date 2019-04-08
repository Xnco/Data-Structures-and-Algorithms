#include "pch.h"
#include "DataStructure.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;
#pragma region 205_同构字符串
/*
给定两个字符串 s 和 t，判断它们是否是同构的。
如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
示例 1:
输入: s = "egg", t = "add"
输出: true
示例 2:
输入: s = "foo", t = "bar"
输出: false
示例 3:
输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度。
*/
// ab,aa false - ab,ca true
// 16ms(36%), 9MB(42%)
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.length() == 0)
		{
			return true;
		}

		map<char, char> s_map;
		map<char, int> t_map;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (s_map.find(s[i]) == s_map.end() && t_map.find(t[i]) == t_map.end())
			{
				s_map[s[i]] = t[i];
				t_map[t[i]] = s[i];
			}
			else
			{
				if (s_map[s[i]] != t[i] || t_map[t[i]] != s[i])
				{
					return false;
				}
			}
		}
		return true;
	}
};
#pragma endregion

int main()
{
	Solution s;
	s.isIsomorphic("ab", "aa");
}

#pragma region 917_仅仅反转字母
/*
给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
示例 1：
输入："ab-cd"
输出："dc-ba"

示例 2：
输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"

示例 3：
输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
 
提示：
S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S 中不包含 \ or "

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-only-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 双指针 
	//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Only Letters.
	//Memory Usage : 8.3 MB, less than 90.91 % of C++ online submissions for Reverse Only Letters.
	string reverseOnlyLetters(string S) {
		int left = 0;
		int right = S.size() - 1;
		while (left < right)
		{
			while (left < right && !isalpha(S[left]))
			{
				++left;
			}
			while (left < right && !isalpha(S[right]))
			{
				--right;
			}
			if (left < right)
			{
				swap(S[left], S[right]);
				++left;
				--right;
			}
		}
		return S;
	}
};
#pragma endregion

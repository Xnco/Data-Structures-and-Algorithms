
#region 680_验证回文字符串Ⅱ 
/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:
输入: "aba"
输出: True

示例 2:
输入: "abca"
输出: True
解释: 你可以删除c字符。

注意:
字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
// 双指针
//Runtime: 140 ms, faster than 16.50% of C# online submissions for Valid Palindrome II.
//Memory Usage: 42.6 MB, less than 100.00% of C# online submissions for Valid Palindrome II.
public bool ValidPalindrome(string s)
{
    int left = 0, right = s.Length - 1;
    while (left <= right)
    {
        if (s[left] == s[right])
        {
            ++left;
            --right;
        }
        else
        {
            return Repeat(s, left + 1, right) || Repeat(s, left, right - 1);
        }
    }
    return true;
}

static bool Repeat(string s, int left, int right)
{
    while (left <= right)
    {
        if (s[left] == s[right])
        {
            ++left;
            --right;
        }
        else
        {
            return false;
        }
    }
    return true;
}
#endregion

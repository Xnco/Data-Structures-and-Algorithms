
#region 1371_每个元音包含偶数次的最长子字符串
/*
给你一个字符串 s ，请你返回满足以下条件的最长子字符串的长度：每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次。
示例 1：
输入：s = "eleetminicoworoep"
输出：13
解释：最长子字符串是 "leetminicowor" ，它包含 e，i，o 各 2 个，以及 0 个 a，u 。

示例 2：
输入：s = "leetcodeisgreat"
输出：5
解释：最长子字符串是 "leetc" ，其中包含 2 个 e 。

示例 3：
输入：s = "bcbcbc"
输出：6
解释：这个示例中，字符串 "bcbcbc" 本身就是最长的，因为所有的元音 a，e，i，o，u 都出现了 0 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//Runtime: 112 ms, faster than 100.00% of C# online submissions for Find the Longest Substring Containing Vowels in Even Counts.
//Memory Usage: 39.9 MB, less than 100.00% of C# online submissions for Find the Longest Substring Containing Vowels in Even Counts.
static int FindTheLongestSubstring(string s)
{
    // 用 ^ 运算分别记录字母出现情况, 奇数次为 1 , 出现偶数次为0
    // 位运算 1<<0, 1<<1, 1<<2, 1<<3, 1<<4 
    // 一个字母过后分两种情况, mark 出现过, 和 mark 没出现过
    int[] dp = new int[1 << 5]; // 记录32种情况第一次出现的下标
    for (int i = 0; i < dp.Length; i++)
    {
        dp[i] = int.MaxValue;
    }
    dp[0] = -1; //特殊情况, mark == 0, 说明次数全部是偶数, res = len
    int ans = 0, mark = 0;
    for (int i = 0; i < s.Length; i++)
    {
        switch (s[i])
        {
            case 'a': mark ^= 1 << 0; break;
            case 'e': mark ^= 1 << 1; break;
            case 'i': mark ^= 1 << 2; break;
            case 'o': mark ^= 1 << 3; break;
            case 'u': mark ^= 1 << 4; break;
        }
        if (dp[mark] == int.MaxValue)
        {
            // mark 没出现过, 说明这种情况是第一次出现, 记录 mark 出现的最小 index
            dp[mark] = i;
        }
        else
        {
            // mark 出现过了, 说明两次出现同一个 mark 之间的元音是偶数, 更新最大值
            ans = Math.Max(ans, i - dp[mark]);
        }
    }

    return ans;
}
        #endregion
using System;

public class Class1
{
	public Class1()
	{
	}
}

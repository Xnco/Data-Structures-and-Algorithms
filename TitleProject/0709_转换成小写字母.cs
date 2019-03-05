using System;

public class Class1
{
	public Class1()
	{
        ToLowerCase("Hellow");
    }

    #region 709_转换成小写字母 
    /*
    实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
    示例 1：
    输入: "Hello"
    输出: "hello"
    示例 2：
    输入: "here"
    输出: "here"
    示例 3：
    输入: "LOVELY"
    输出: "lovely"
    */
    // 184ms, 20.2MB
    static string ToLowerCase(string str)
    {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.Length; i++)
        {
            int tmp = str[i];
            sb.Append((char)(tmp + (tmp < 91 && tmp > 64 ? 32 : 0)));
        }

        return sb.ToString();
    }

    // :>
    static string ToLowerCase2(string str)
    {
        return str.ToLower();
    }

    #endregion
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _771_宝石和石头
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        #region 771. 宝石和石头 (简单)
        /*
          给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
        J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。 
        */
        static int NumJewelsInStones(string J, string S)
        {
            // 暴力
            int num = 0;
            for (int i = 0; i < S.Length; i++)
            {
                for (int j = 0; j < J.Length; j++)
                {
                    if (S[i] == J[j])
                    {
                        num++;
                    }
                }
            }
            return num;
        }
        #endregion 
    }
}

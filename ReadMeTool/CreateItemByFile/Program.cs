using System;
using System.IO;

namespace CreateItemByFile
{
    class Program
    {
        static string path = @"E:\GitHub_P\Data-Structures-and-Algorithms\";

        static string csPath = @"TitleProject";
        static string csHttpsStr = @"(https://github.com/Xnco/Data-Structures-and-Algorithms/blob/master/TitleProject/{0}_{1}.cs)";

        static string cppPath = @"TitleProject_Cpp";
        static string cppHttpsStr = @"(https://github.com/Xnco/Data-Structures-and-Algorithms/blob/master/TitleProject_Cpp/{0}_{1}.cpp)";

        static string readmePath = @"README.md";

        static void Main(string[] args)
        {
            //ChangedReadMeByCpp(cppPath, cppHttpsStr);
            //ChangedReadMeByCpp(csPath, csHttpsStr);
        }

        static void ChangedReadMeByCpp(string dirPath, string httpStr)
        {
            string[] all = File.ReadAllLines(path + readmePath);
            DirectoryInfo dir = new DirectoryInfo(path + dirPath);
            FileInfo[] allFiles = dir.GetFiles();

            string[] newAll = new string[all.Length];

            for (int i = 0; i < all.Length; i++)
            {
                if (all[i].IndexOf("<font size=4>") != -1)
                {
                    if (all[i].IndexOf("https") == -1)
                    {
                        int left = all[i].IndexOf('[');
                        int right = all[i].IndexOf(']');
                        if (left != -1 && right != -1)
                        {
                            string fileName = all[i].Substring(left + 1, right - left - 1);
                            string fileNum = all[i].Substring(2, all[i].IndexOf('-') - 3);
                            int Num;
                            if (int.TryParse(fileNum, out Num));
                            {
                                for (int j = 0; j < allFiles.Length; j++)
                                {
                                    string[] nameList = allFiles[j].Name.Split("_");
                                    if (nameList.Length >= 2)
                                    {
                                        string fileName2 = nameList[1].Split(".")[0];
                                        if (fileName2 == fileName)
                                        {
                                            all[i] = all[i].Insert(right + 1, string.Format(httpStr,
                                                Num.ToString("0000"), fileName.Replace(" ", "")));
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {

                    }
                }
                newAll[i] = all[i];
            }

            if (newAll.Length != 0)
            {
                File.WriteAllLines(path + readmePath, newAll);
            }
        }
    }
}

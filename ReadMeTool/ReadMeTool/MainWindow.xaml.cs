using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ReadMeTool
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        //todo: https://github.com/dotnet/ILMerge 用工具打包成一个exe

        static string path = @"E:\GitHub_P\Data-Structures-and-Algorithms\";

        static string csPath = @"..\TitleProject";
        static string csHttpsStr = @"(https://github.com/Xnco/Data-Structures-and-Algorithms/blob/master/TitleProject/{0}_{1}.cs)";

        static string cppPath = @"..\TitleProject_Cpp";
        static string cppHttpsStr = @"(https://github.com/Xnco/Data-Structures-and-Algorithms/blob/master/TitleProject_Cpp/{0}_{1}.cpp)";

        static string readmePath = @"..\README.md";

        enum LangType
        {
            Cpp, CSharp,
        }

        enum DiffType
        {
            简单, 中等, 困难,
        }

        public MainWindow()
        {
            InitializeComponent();
        }

        //*1 - < font size = 4 >[两数之和] </ font > -简单 - 2
        private void OnClick_Finish(object sender, RoutedEventArgs e)
        {
            string input_Content;
            int input_Num;
            string input_Title;
            if (!GetContent(out input_Content, out input_Num, out input_Title))
            {
                return;
            }

            if(!File.Exists(readmePath))
            {
                MessageBox.Show("ReadMe 文件不存在, 请确认工具所在路径!");
                return;
            }

            string folderPath = "";
            switch ((LangType)LangType_ComboBox.SelectedIndex)
            {
                case LangType.Cpp:
                    folderPath = cppPath;
                    break;
                case LangType.CSharp:
                    folderPath = csPath;
                    break;
                default:
                    return ;
            }

            if(!Directory.Exists(folderPath))
            {
                MessageBox.Show((LangType)LangType_ComboBox.SelectedIndex + "对应的工程不存在, 请确认工具或工程路径!");
                return;
            }

            string[] all = File.ReadAllLines(readmePath);
            DirectoryInfo dir = new DirectoryInfo(folderPath);
            FileInfo[] allFiles = dir.GetFiles();

            List<string> res = all.ToList<string>();
            for (int i = 0; i < res.Count; i++)
            {
                if (res[i].IndexOf("<font size=4>") != -1)
                {
                    string fileNum = res[i].Substring(2, all[i].IndexOf('-') - 3);
                    int tempNum;
                    if(int.TryParse(fileNum, out tempNum) && tempNum > input_Num)
                    {
                        res.Insert(i, input_Content);
                        break;
                    }
                }
            }
            File.WriteAllLines(readmePath, res);
        }

        bool GetContent(out string content, out int num, out string title)
        {
            content = "* ";
            num = 0;
            title = "";
            if (string.IsNullOrEmpty(Num_Text.Text) || string.IsNullOrEmpty(Title_Text.Text))
            {
                return false;
            }

            // 编号
            if (!int.TryParse(Num_Text.Text, out num))
            {
                MessageBox.Show("题目编号必须是数字, 请确认");
                return false;
            }
            content += num.ToString();

            // 题目名
            content += " - <font size=4>[";
            title = Title_Text.Text;
            content += title;
            content += "]";

            // 代码类型和https
            string httpsPath = "";
            string folderPath = "";
            switch ((LangType)LangType_ComboBox.SelectedIndex)
            {
                case LangType.Cpp:
                    folderPath = cppPath;
                    httpsPath = cppHttpsStr;
                    break;
                case LangType.CSharp:
                    folderPath = csPath;
                    httpsPath = csHttpsStr;
                    break;
                default:
                    MessageBox.Show("暂不支持的代码类型, 请重新选择");
                    return false;
            }
            content += string.Format(httpsPath, num.ToString("0000"), Title_Text.Text);

            content += "</font>";

            // 难度
            switch ((DiffType)Difficulty_ComboBox.SelectedIndex)
            {
                case DiffType.简单:
                    content += " - " + DiffType.简单;
                    break;
                case DiffType.中等:
                    content += " - " + DiffType.中等;
                    break;
                case DiffType.困难:
                    content += " - " + DiffType.困难;
                    break;
                default:
                    break;
            }

            // 解法
            if (!string.IsNullOrEmpty(FuncNum_Text.Text))
            {
                content += " - " + FuncNum_Text.Text;
            }
            return true;
        }
    }
}

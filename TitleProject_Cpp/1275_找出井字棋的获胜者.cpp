
#pragma region 1275_找出井字棋的获胜者
/*
A 和 B 在一个 3 x 3 的网格上玩井字棋。
井字棋游戏的规则如下：
玩家轮流将棋子放在空方格 (" ") 上。
第一个玩家 A 总是用 "X" 作为棋子，而第二个玩家 B 总是用 "O" 作为棋子。
"X" 和 "O" 只能放在空方格中，而不能放在已经被占用的方格上。
只要有 3 个相同的（非空）棋子排成一条直线（行、列、对角线）时，游戏结束。
如果所有方块都放满棋子（不为空），游戏也会结束。
游戏结束后，棋子无法再进行任何移动。
给你一个数组 moves，其中每个元素是大小为 2 的另一个数组（元素分别对应网格的行和列），它按照 A 和 B 的行动顺序（先 A 后 B）记录了两人各自的棋子位置。
如果游戏存在获胜者（A 或 B），就返回该游戏的获胜者；如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。
你可以假设 moves 都 有效（遵循井字棋规则），网格最初是空的，A 将先行动。

示例 1：
输入：moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
输出："A"
解释："A" 获胜，他总是先走。
"X  "    "X  "    "X  "    "X  "    "X  "
"   " -> "   " -> " X " -> " X " -> " X "
"   "    "O  "    "O  "    "OO "    "OOX"

示例 2：
输入：moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
输出："B"
解释："B" 获胜。
"X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
"   " -> " O " -> " O " -> " O " -> "XO " -> "XO "
"   "    "   "    "   "    "   "    "   "    "O  "

示例 3：
输入：moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
输出："Draw"
输出：由于没有办法再行动，游戏以平局结束。
"XXO"
"OOX"
"XOX"

示例 4：
输入：moves = [[0,0],[1,1]]
输出："Pending"
解释：游戏还没有结束。
"X  "
" O "
"   "

提示：
1 <= moves.length <= 9
moves[i].length == 2
0 <= moves[i][j] <= 2
moves 里没有重复的元素。
moves 遵循井字棋的规则。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-winner-on-a-tic-tac-toe-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	//Runtime: 4 ms, faster than 59.70% of C++ online submissions for Find Winner on a Tic Tac Toe Game.
	//Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Find Winner on a Tic Tac Toe Game.
	string tictactoe(vector<vector<int>>& moves)
	{
		vector<vector<int>> map(3, vector<int>(3, 0));
		bool bIsFirst = true;
		for (size_t i = 0; i < moves.size(); i++)
		{
			int x = moves[i][0];
			int y = moves[i][1];
			int target = bIsFirst ? 1 : 2;
			map[x][y] = target;
			if (i > 3 &&
				(IsWin(map, x, y, 1, 1, target)
					|| IsWin(map, x, y, -1, 1, target)
					|| IsWin(map, x, y, 0, 1, target)
					|| IsWin(map, x, y, 1, 0, target)))
			{
				return bIsFirst ? "B" : "A";
			}

			bIsFirst = !bIsFirst;
		}
		return moves.size() > 8 ? "Draw" : "Pending";
	}

	bool IsWin(vector<vector<int>> map, int x, int y, int x_dir, int y_dir, int target)
	{
		int x_offset = x_dir, y_offset = y_dir, res = 1;
		while (x + x_offset >= 0 && y + y_offset >= 0 && x + x_offset < map.size() && y + y_offset < map.size())
		{
			if (map[x + x_offset][y + y_offset] == target)
			{
				++res;
				x_offset += x_dir;
				y_offset += y_dir;
			}
			else
			{
				break;
			}
		}
		x_offset = -x_dir;
		y_offset = -y_dir;
		while (x + x_offset >= 0 && y + y_offset >= 0 && x + x_offset < map.size() && y + y_offset < map.size())
		{
			if (map[x + x_offset][y + y_offset] == target)
			{
				++res;
				x_offset -= x_dir;
				y_offset -= y_dir;
			}
			else
			{
				break;
			}
		}
		return res > 2;
	}
};
#pragma endregion

int main()
{
	Solution s;
	vector<vector<int>> test{ {0, 0}, { 1, 1 }, { 2, 0 },{ 1, 0 },{ 1, 2 }, { 2, 1 },{ 0,1 }, { 0,2 },{ 2, 2 } };
	s.tictactoe(test);
}
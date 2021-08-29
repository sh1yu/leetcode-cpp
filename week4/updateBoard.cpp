//
// Created by psycode on 2021/8/29.
//
// 让我们一起来玩扫雷游戏！
//
// 给定一个代表游戏板的二维字符矩阵。
// 'M'代表一个未挖出的地雷，
// 'E'代表一个未挖出的空方块，
// 'B'代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，
// 数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，
// 'X'则表示一个已挖出的地雷。
//
// 现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
//
// 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为'X'。
// 如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
// 如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
// 如果在此次点击中，若无更多方块可被揭露，则返回面板。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/minesweeper

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 思路：必要时直接回溯周围节点,计算节点周围雷数量即可
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        backtrack(board, click[0], click[1]);
        return board;
    }

    void backtrack(vector<vector<char>> &board, int line, int column) {
        if (line < 0 || column < 0 || line >= board.size() || column >= board[0].size()) {
            return;
        }
        switch (board[line][column]) {
            case 'M':
                board[line][column] = 'X';
                return;
            case 'E':
                int count = mineCount(board, line, column);
                if (count > 0) {
                    board[line][column] = '0' + count;
                } else {
                    board[line][column] = 'B';
                    // 递归揭露所有其他相邻方块
                    backtrack(board, line - 1, column);
                    backtrack(board, line + 1, column);
                    backtrack(board, line, column - 1);
                    backtrack(board, line, column + 1);
                    backtrack(board, line - 1, column - 1);
                    backtrack(board, line - 1, column + 1);
                    backtrack(board, line + 1, column - 1);
                    backtrack(board, line + 1, column + 1);
                }
        }
    }

    int mineCount(vector<vector<char>> &board, int line, int column) {
        int count = 0;
        //上
        if (line > 0 && board[line - 1][column] == 'M') {
            count++;
        }
        //下
        if (line < board.size() - 1 && board[line + 1][column] == 'M') {
            count++;
        }
        //左
        if (column > 0 && board[line][column - 1] == 'M') {
            count++;
        }
        //右
        if (column < board[0].size() - 1 && board[line][column + 1] == 'M') {
            count++;
        }
        //左上
        if (line > 0 && column > 0 && board[line - 1][column - 1] == 'M') {
            count++;
        }
        //左下
        if (line < board.size() - 1 && column > 0 && board[line + 1][column - 1] == 'M') {
            count++;
        }
        //右上
        if (line > 0 && column < board[0].size() - 1 && board[line - 1][column + 1] == 'M') {
            count++;
        }
        //右下
        if (line < board.size() - 1 && column < board[0].size() - 1 && board[line + 1][column + 1] == 'M') {
            count++;
        }
        return count;
    }
};

int main(int argc, const char *argv[]) {

    Solution solution;

    vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'M', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'}};
    vector<int> click = {3, 0};
    auto output = solution.updateBoard(board, click);
    for (vector<char> &line: output) {
        for (char c: line) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
//
// Created by psycode on 2021/8/29.
//
// 200. 岛屿数量
// 给你一个由'1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
//
//岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
//
//此外，你可以假设该网格的四条边均被水包围。
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/number-of-islands

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 思路：深度搜索
    // 时间复杂度：O(mn)
    // 空间复杂度：O(mn)
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        for (auto i = 0; i < grid.size(); i++) {
            for (auto j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                count++;
                changeIsland(grid, i, j);
            }
        }

        return count;
    }

    void changeIsland(vector<vector<char>> &grid, int i, int j) {
        if (grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        if (i > 0) {
            changeIsland(grid, i-1, j);
        }
        if (i < grid.size() - 1) {
            changeIsland(grid, i + 1, j);
        }
        if (j > 0) {
            changeIsland(grid, i, j - 1);
        }
        if (j < grid[0].size() - 1) {
            changeIsland(grid, i, j + 1);
        }
    }
};

int main(int argc, const char *argv[]) {

    Solution s;

    vector<vector<char>> grid =
            {{'1', '1', '1', '1', '0'},
             {'1', '1', '0', '1', '0'},
             {'1', '1', '0', '0', '0'},
             {'0', '0', '0', '0', '0'}};
    cout << s.numIslands(grid) << endl;

    grid = {{'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}};
    cout << s.numIslands(grid) << endl;

    grid = {{'1', '0', '1', '1', '1'},
            {'1', '0', '1', '0', '1'},
            {'1', '1', '1', '0', '1'}};
    cout << s.numIslands(grid) << endl;

    return 0;
}
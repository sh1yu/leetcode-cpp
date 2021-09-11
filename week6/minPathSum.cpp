//
// Created by psycode on 2021/9/11.
//
// 64. 最小路径和
// 给定一个包含非负整数的 m x n网格grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
//说明：每次只能向下或者向右移动一步。
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/minimum-path-sum

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 思路：动态规划。由于每个点的最小值只和当前节点的上侧节点和左侧节点有关，可以使用一维数组记录最优值
    // 时间复杂度：O(mn)
    // 空间复杂度：O(n)
    int minPathSum(vector<vector<int>> &grid) {

        int dp[grid[0].size()];
        dp[0] = grid[0][0];
        for (int j = 1; j < grid[0].size(); j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        for (int i = 1; i < grid.size(); i++) {
            dp[0] = dp[0] + grid[i][0];
            for (int j = 1; j < grid[0].size(); j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }

        return dp[grid[0].size() - 1];
    }
};

int main(int argc, const char *argv[]) {
    Solution s;

    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    cout << s.minPathSum(grid) << endl;

    grid = {{1, 2, 3},
            {4, 5, 6}};
    cout << s.minPathSum(grid) << endl;
}
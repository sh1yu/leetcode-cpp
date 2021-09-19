//
// Created by sypeng on 2021/9/19.
//
// 312. 戳气球
// 有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
//
//现在要求你戳破所有的气球。
// 戳破第 i 个气球，你可以获得  nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。
// 这里的 i - 1 和 i + 1 代表和  i  相邻的两个气球的序号。
// 如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
//
//求所能获得硬币的最大数量。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/burst-balloons

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> rec(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j <= n + 1; j++) {
                for (int k = i + 1; k < j; k++) {
                    int sum = val[i] * val[k] * val[j];
                    sum += rec[i][k] + rec[k][j];
                    rec[i][j] = max(rec[i][j], sum);
                }
            }
        }
        return rec[0][n + 1];
    }
};

int main(int argc, const char *argv[]) {
    Solution s;

    vector<int> nums = {3,1,5,8};
    cout << s.maxCoins(nums) << endl;

    return 0;
}

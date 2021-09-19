//
// Created by sypeng on 2021/9/19.
//
// 552. 学生出勤记录 II
// 可以用字符串表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：
//'A'：Absent，缺勤
//'L'：Late，迟到
//'P'：Present，到场
//如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：
//
//按 总出勤 计，学生缺勤（'A'）严格 少于两天。
//学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
//给你一个整数 n ，表示出勤记录的长度（次数）。请你返回记录长度为 n 时，可能获得出勤奖励的记录情况 数量 。答案可能很大，所以返回对 109 + 7 取余 的结果。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/student-attendance-record-ii

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    static constexpr int MOD = 1'000'000'007;

    int checkRecord(int n) {

        // 长度，A 的数量，结尾连续 L 的数量
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            // 以 P 结尾的数量
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 2; k++) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
                }
            }
            // 以 A 结尾的数量
            for (int k = 0; k <= 2; k++) {
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
            }
            // 以 L 结尾的数量
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= 2; k++) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                }
            }
        }

        int sum = 0;
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 2; k++) {
                sum = (sum + dp[n][j][k]) % MOD;
            }
        }
        return sum;
    }
};


int main(int argc, const char *argv[]) {

    Solution s;

    cout << s.checkRecord(10101) << endl;

    return 0;
}

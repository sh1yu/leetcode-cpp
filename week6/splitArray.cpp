//
// Created by sypeng on 2021/9/19.
//
// 410. 分割数组的最大值
// 给定一个非负整数数组 nums 和一个整数 m ，你需要将这个数组分成 m 个非空的连续子数组。
//
//设计一个算法使得这 m 个子数组各自和的最大值最小。

#include<iostream>
#include<vector>
#include <climits>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return (int)f[n][m];
    }
};

int main(int argc, const char *argv[]) {
    Solution s;

    vector<int> nums = {7,2,5,10,8};
    cout << s.splitArray(nums, 2) << endl;

    return 0;
}
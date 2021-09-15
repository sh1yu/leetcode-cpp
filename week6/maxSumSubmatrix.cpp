//
// Created by sypeng on 2021/9/15.
//
// 363. 矩形区域不超过 K 的最大数值和
// 给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。
//
//题目数据保证总会存在一个数值和不超过 k 的矩形区域。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k

#include <vector>
#include <iostream>
#include <climits>
#include <set>

using namespace std;

class Solution {
public:

    // 还是没啥思路。。本来想是不是dp的，想了半天也不知道转移方程该怎么写
    // 暴力的话倒是可以，直接遍历每一个矩形（左上角和右下角，O(n^2m^2)），每一个矩形再判断其数值和，总复杂度为O(nm^3)
    // 一看难度为困难就放弃了。看官方题解使用了前缀和，据说前缀和是一个很经典的手段，我得研究一下解法
    // 时间复杂度O(m^2nlogn)
    // 空间复杂度O(n)
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int ans = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) { // 枚举上边界

            vector<int> sum(n); //sum为“每列”的元素之和，注意这里的列高是（i到j），i,j都是从0到m

            for (int j = i; j < m; ++j) { // 枚举下边界
                for (int c = 0; c < n; ++c) {
                    sum[c] += matrix[j][c]; // 更新每列的元素和
                }
                set<int> sumSet{0}; //有序集合，该集合为前缀和集合（每一个位置产生的s的集合）
                int s = 0; // s 为 每列的元素和 的 前缀和
                for (int v : sum) {
                    s += v;
                    // 往前查找“前缀和之差为恰好不超过k”的位置lb
                    // 也就是说，该位置到s所在的位置之间的原始元素之和“恰好小于k”
                    auto lb = sumSet.lower_bound(s - k);
                    if (lb != sumSet.end()) {
                        ans = max(ans, s - *lb); //找到了需要的lb，使用ans找最大值即可
                    }
                    sumSet.insert(s);
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;
    vector<vector<int>> matrix = {{1, 0,  1},
                                  {0, -2, 3}};

    cout << s.maxSumSubmatrix(matrix, 2) << endl;

    matrix = {{2, 2, -1}};

    cout << s.maxSumSubmatrix(matrix, 3) << endl;
}
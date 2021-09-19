//
// Created by sypeng on 2021/9/19.
//

// 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数。
//
//你可以对一个单词进行如下三种操作：
//
//插入一个字符
//删除一个字符
//替换一个字符
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/edit-distance

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    // 越来越感觉到：
    // 贪心代码很简单，但是要想证明正确性往往需要用到数学证明
    // dp稍微复杂一些，好在套路一致，但是想要找到正确的转移方程真的不容易
    // 其他的算法算法在某些题目上很好用，但是不够通用性，一不留神就出错或者不适用
    // 暴力枚举想法最简单，实现上也算简单，但是时间复杂度真的受不了
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // 有一个字符串为空串
        if (n * m == 0) return n + m;

        // DP 数组
        int D[n + 1][m + 1];

        // 边界状态初始化
        for (int i = 0; i < n + 1; i++) {
            D[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            D[0][j] = j;
        }

        // 计算所有 DP 值
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int left = D[i - 1][j] + 1;
                int down = D[i][j - 1] + 1;
                int left_down = D[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) left_down += 1;
                D[i][j] = min(left, min(down, left_down));

            }
        }
        return D[n][m];
    }
};

int main(int argc, const char *argv[]) {

    Solution s;
    cout << s.minDistance("intention", "execution") << endl;
}
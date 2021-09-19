//
// Created by psycode on 2021/9/12.
//
// 91. 解码方法
// 一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// 要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：
//
// "AAJF" ，将消息分组为 (1 1 10 6)
// "KJF" ，将消息分组为 (11 10 6)
// 注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。
//
// 给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。
//
// 题目数据保证答案肯定是一个 32 位 的整数。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/decode-ways

#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:

    // 思路：自己使用动态规划但是没有成功，转移方程不太正确
    // 这里将官方题解稍微做了改动，虽然更冗长了，但是让自己更好理解
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int numDecodings(string s) {

        int n = s.size();

        int a = 0, b = 1, c = 0;

        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] > '0') {

                // 在当前字符不是0时，说明可以作为单个数字的解码方式加入，解码次数和之前解码次数相同(状态+1位数字)
                c = b;

                if (i > 1 && s[i - 2] > '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                    // 当前字符不是0且可以和上个字符组成合法字符，解码次数为上次解码次数(状态+1位数字)+上上次解码次数(状态+2位数字)
                    c = a + b;
                }

            } else {

                // 在当前字符为0时，当前数字不可能作为单个数字解码方式加入
                c = 0;

                // 在当前字符为0时，当前数字不可能作为单个数字解码方式加入，解码次数为上上次解码次数(状态+2位数字)
                if (i > 1 && s[i - 2] > '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                    c = a;
                }
            }

            tie(a, b) = {b, c};
        }
        return c;
    }
};

int main(int argc, const char *argv[]) {
    Solution s;

    cout << s.numDecodings("12") << endl;
    cout << s.numDecodings("226") << endl;
    cout << s.numDecodings("0") << endl;
    cout << s.numDecodings("06") << endl;
    cout << s.numDecodings("10") << endl;
    cout << s.numDecodings("2101") << endl;
    cout << s.numDecodings("1123") << endl;

    return 0;
}
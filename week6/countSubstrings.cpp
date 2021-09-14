//
// Created by psycode on 2021/9/14.
//
// 647. 回文子串
// 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
//
//回文字符串 是正着读和倒过来读一样的字符串。
//
//子字符串 是字符串中的由连续字符组成的一个序列。
//
//具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/palindromic-substrings

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:

    // 思路：动态规划，转移方程 f(n) = f(n-1) + s(n) ，其中s(n)为以n为结束字符串的回文串个数
    // 这种是假的动态规划，虽然结果正确，但是复杂度较高，和暴力法没啥两样，没有充分利用子问题重复性
    // 时间复杂度：O（n^3)
    // 空间复杂度: O(1)
    int countSubstrings(string s) {

        int res = 1;
        for (int i = 1; i < s.size(); i++) {
            int cur = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    int k = i, l = j;
                    while (k > l && s[k] == s[l]) {
                        k--;
                        l++;
                    };
                    if (k <= l) cur++;
                }
            }
            res = res + cur;
        }

        return res;
    }

    // 官方解法，找到回文中心，然后分别左右扩展
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(1)
    int countSubstrings2(string s) {

        int n = s.size(), ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, const char *argv[]) {

    Solution s;
    cout << s.countSubstrings("abc") << " " << s.countSubstrings2("abc") << endl;
    cout << s.countSubstrings("aaa") << " " << s.countSubstrings2("aaa") << endl;
    cout << s.countSubstrings("fdsklf") << " " << s.countSubstrings2("fdsklf") << endl;
    cout << s.countSubstrings("longtimenosee") << " " << s.countSubstrings2("longtimenosee") << endl;
}
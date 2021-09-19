//
// Created by sypeng on 2021/9/16.
//
// 32. 最长有效括号
// 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    // 这种情况比较好想
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                    // 此时i-1的位置必然有一个匹配位置，找到这个匹配位置 i - dp[i - 1]
                    // i的匹配位置为  i - dp[i - 1] - 1
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    // i的匹配位置匹配，i的匹配数量为dp[i - 1] + 2
                    // 但是 dp[i - dp[i - 1] - 2] 可能还存在一些连续的前置匹配括号，需要也加上
                    dp[i] = dp[i - 1] + ((i - dp[i - 1] -2 ) >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }

    int longestValidParentheses2(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (right > left) {
                left = right = 0;
            } else if (right == left){ //不是在相等的时候判断的话，会导致"()(()"这种不连续的字串混在一起计数
                maxlength = max(maxlength, 2 * right);
            }
        }
        left = 0, right = 0;
        for (int i =s.length()-1; i > 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left > right) {
                left = right = 0;
            } else if (right == left){
                maxlength = max(maxlength, 2 * left);
            }
        }
        return maxlength;
    }
};

int main(int argc, const char *argv[]) {

    Solution s;
    cout << s.longestValidParentheses("(()") << endl;
    cout << s.longestValidParentheses(")()())") << endl;
    cout << s.longestValidParentheses("") << endl;

    cout << s.longestValidParentheses2("()(()") << endl;

    return 0;
}
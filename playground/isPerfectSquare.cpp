//
// Created by psycode on 2021/8/29.
//
//367. 有效的完全平方数
//
// 给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
//
//进阶：不要 使用任何内置的库函数，如 sqrt 。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/valid-perfect-square

#include <iostream>

using namespace std;

class Solution {
public:

    // 二分查找
    bool isPerfectSquare(int num) {
        return binarySearch(num, 0, num / 2);
    }

    bool binarySearch(int num, int start, int end) {
        if (num == 1) {
            return true;
        }
        if (start > end) {
            return false;
        };
        long mid = (start + end) / 2;
        long res = mid * mid;
        if (res < num) {
            return binarySearch(num, mid + 1, end);
        } else if (res > num) {
            return binarySearch(num, start, mid - 1);
        } else {
            return true;
        }
    }
};

int main(int argc, const char *argv[]) {

    Solution s;
    cout << "16:" << s.isPerfectSquare(16) << endl;
    cout << "14:" <<s.isPerfectSquare(14) << endl;
    return 0;
}
//
// Created by psycode on 2021/8/28.
//
// 860. 柠檬水找零
// 在柠檬水摊上，每一杯柠檬水的售价为5美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
//
//每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
//
//注意，一开始你手头没有任何零钱。
//
//给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回true，否则返回 false。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/lemonade-change


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 思路：
    // 直接每次在股票最小值时买入，然后在最高值时卖出
    // 直接模拟交易，每次尽量使用最大面值的零钱
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    bool lemonadeChange(vector<int> &bills) {
        int fiveBox = 0;
        int tenBox = 0;

        for (int &bill: bills) {
            if (bill == 5) {
                fiveBox++;
                continue;
            }
            if (bill == 10) {
                tenBox++;
                fiveBox--;
                if (fiveBox < 0) {
                    return false;
                }
                continue;
            }
            if (bill == 20) {
                if (tenBox > 0) {
                    tenBox--;
                    fiveBox--;
                } else {
                    fiveBox -= 3;
                }
                if (fiveBox < 0) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char *argv[]) {

    Solution s;

    vector<int> bills = {5, 5, 5, 10, 20};
    cout << s.lemonadeChange(bills) << endl;

    bills = {5, 5, 10, 10, 20};
    cout << s.lemonadeChange(bills) << endl;

    bills = {5, 5, 10};
    cout << s.lemonadeChange(bills) << endl;

    bills = {10, 10};
    cout << s.lemonadeChange(bills) << endl;

    return 0;
}
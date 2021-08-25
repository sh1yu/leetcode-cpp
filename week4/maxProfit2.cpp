//
// Created by sypeng on 2021/8/25.
//
// 122. 买卖股票的最佳时机 II
//给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。
//
//设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
//
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 思路：
    // 直接每次在股票最小值时买入，然后在最高值时卖出
    // 和官方dp相比，一个是"预知未来"，一个是"改变过去"
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int maxProfit2(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int maxProfit = 0;
        int gotPrice = 0;
        bool isGot = false;
        for (auto i = 0; i < prices.size(); i++) {
            if (i == prices.size() - 1) {
                // 最后一天如果发现还在持有股票，直接卖出
                if (isGot) {
                    maxProfit += prices.at(i) - gotPrice;
                }
                break;
            }

            if (isGot) {
                // 当前已经购买，如果"未来"会跌，直接卖出计算受益；否则继续持有
                if (prices.at(i+1) < prices.at(i)) {
                    maxProfit += prices.at(i) - gotPrice;
                    isGot = false;
                }
            } else {
                // 当前未购买，如果"未来"会涨，直接买入
                if (prices.at(i+1) > prices.at(i)) {
                    gotPrice = prices.at(i);
                    isGot = true;
                }
            }
        }

        return maxProfit;
    }
};

int main(int argc, const char *argv[]) {

    Solution s;

    vector<int> expected = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit2(expected) << endl;

    expected = {1, 2, 3, 4, 5};
    cout << s.maxProfit2(expected) << endl;

    expected = {7, 6, 4, 3, 1};
    cout << s.maxProfit2(expected) << endl;

    expected = {1};
    cout << s.maxProfit2(expected) << endl;

    return 0;
}
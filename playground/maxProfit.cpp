//
// Created by sypeng on 2021/8/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int inf = 1e9;
        int minPrice = inf;
        int maxProfit = 0;
        for (int price: prices) {
            maxProfit = max(maxProfit, price - minPrice);
            minPrice = min(price, minPrice);
        }
        return maxProfit;
    }
};

int main(int argc, const char *argv[]) {
    vector<int> expected = {7, 1, 5, 3, 6, 4};

    Solution s;
    cout << s.maxProfit(expected) << endl;

    return 0;
}
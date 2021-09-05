//
// Created by psycode on 2021/9/3.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> h;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            auto f = h.find(nums[i]);
            if (f != h.end()) {
                result.emplace_back(f->second);
                result.emplace_back(i);
                return result;
            }
            h[target - nums[i]] = i;
        }

        return result;
    }
};


int main(int argc, const char *argv[]) {

    Solution s;

    vector<int> input = {2, 7, 11, 15};
    auto res = s.twoSum(input, 9);
    for (int &item : res) {
        cout << item << endl;
    }

    return 0;
}
//
//  main.cpp
//  permute
//
//  Created by sypeng on 2021/8/24.
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


class Solution {
private:
    void backtrack(vector<vector<int>> &res,
                   vector<int> &nums,
                   int level,
                   vector<bool> &visit,
                   vector<int> &path) {

        if (level == nums.size()) {
            res.emplace_back(path);
            return;
        }
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (visit[i]) {
                continue;
            }
            path.emplace_back(nums[i]);
            visit[i] = true;
            backtrack(res, nums, level + 1, visit, path);
            path.pop_back();
            visit[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<bool> visit;
        vector<int> path;
        visit.resize(nums.size());
        backtrack(res, nums, 0, visit, path);
        return res;
    }
};

string format_vectors(vector<vector<int>> &res) {
    stringstream ss;

    for (auto cur = res.begin(); cur != res.end(); cur++) {
        if (cur != res.begin()) {
           ss << endl;
        }
        ss << "[";
        for (auto i = cur->begin(); i != cur->end(); i++) {
            if (i != cur->begin()) {
                ss << ", ";
            }
            ss << *i;
        }
        ss << "]";
    }
    return ss.str();
}

int main(int argc, const char *argv[]) {

    vector<int> expected = {1, 2, 3};

    Solution s;
    vector<vector<int>> res = s.permute(expected);
    cout << format_vectors(res) << endl;

    return 0;
}



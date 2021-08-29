//
// Created by psycode on 2021/8/30.
//
// 45. 跳跃游戏 II
//
// 给你一个非负整数数组nums ，你最初位于数组的第一个位置。
//
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//你的目标是使用最少的跳跃次数到达数组的最后一个位置。
//
//假设你总是可以到达数组的最后一个位置。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/jump-game-ii

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        // 下一次可以到达的最远位置
        int maxLocation = 0;
        // 当前不增加步数的情况下能到达的最远位置
        int end = 0;
        // 当前步数
        int step = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            //最大位置到不了当前位置，失败
            if (maxLocation < i) {
                return -1;
            }
            maxLocation = max(maxLocation, nums[i] + i);
            if (i == end) {
                end = maxLocation;
                ++step;
            }
        }
        return step;
    }
};

int main(int argc, const char *argv[]) {

    Solution solution;

    vector<int> nums = {2, 3, 1, 1, 4};
    cout << solution.jump(nums) << endl;

    nums = {2, 3, 0, 1, 4};
    cout << solution.jump(nums) << endl;

    return 0;
}
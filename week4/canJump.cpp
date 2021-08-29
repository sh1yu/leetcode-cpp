//
// Created by psycode on 2021/8/29.
//
//55. 跳跃游戏
//给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
//
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//判断你是否能够到达最后一个下标。
//
// https://leetcode-cn.com/problems/jump-game/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 思路：从前往后遍历，查找每个节点能到达的最大位置，并记录最大位置
    // 如果这个最大位置大于等于数组本身的长度-1，说明可以到达最后一个位置
    // 时间复杂度 O(n)
    // 空间复杂度 O(1)
    bool canJump(vector<int> &nums) {
        int maxLocation = 0;
        for (int i = 0; i < nums.size(); i++) {
            //最大位置到不了当前位置，失败
            if (maxLocation < i) {
                return false;
            }
            int targetLocation = nums[i] + i;
            if (maxLocation < targetLocation) {
                maxLocation = targetLocation;
                if (maxLocation >= nums.size() - 1) {
                    return true;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char *argv[]) {

    Solution solution;

    vector<int> nums = {2, 3, 1, 1, 4};
    cout << solution.canJump(nums) << endl;

    nums = {3, 2, 1, 0, 4};
    cout << solution.canJump(nums) << endl;

    return 0;
}
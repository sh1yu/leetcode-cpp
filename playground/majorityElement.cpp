//
// Created by psycode on 2021/8/29.
//
// 169. 多数元素
// 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于⌊ n/2 ⌋的元素。
//
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/majority-element

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 思路：对抗：遇见自己+1，遇见其他-1直到0，然后替换为自己
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int majorityElement(vector<int> &nums) {
        int majority = -1;
        int majorityCount = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (majority == nums[i]) {
                majorityCount++;
                continue;
            }
            if (majorityCount > 0) {
                majorityCount--;
                continue;
            }
            majority = nums[i];
            majorityCount = 1;
        }
        return majority;
    }
};

int main(int argc, const char *argv[]) {

    Solution s;

    vector<int> input = {3, 2, 3};
    cout << s.majorityElement(input) << endl;

    input = {2, 2, 1, 1, 1, 2, 2};
    cout << s.majorityElement(input) << endl;

    return 0;
}
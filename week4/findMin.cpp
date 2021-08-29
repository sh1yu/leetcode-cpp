//
// Created by psycode on 2021/8/30.
//
// 153. 寻找旋转排序数组中的最小值
// 已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。
// 例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
//若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
//若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
//注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
//
//给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 思路：直接二分查找
    int findMin(vector<int> &nums) {
        int found = binarySearch(nums, 0, nums.size() - 1);
        return nums[found];
    }

    int binarySearch(vector<int> &nums, int start, int end) {
        if (nums[start] <= nums[end]) {
            return start;
        }
        if (start >= end - 1) {
            return end;
        }

        int mid = (start + end) / 2;
        if (nums[start] <= nums[mid]) {
            return binarySearch(nums, mid, end);
        } else {
            return binarySearch(nums, start, mid);
        }
    }
};

int main(int argc, const char *argv[]) {

    Solution solution;

    vector<int> nums = {3, 4, 5, 1, 2};
    cout << solution.findMin(nums) << endl;

    nums = {4, 5, 6, 7, 0, 1, 2};
    cout << solution.findMin(nums) << endl;

    nums = {11, 13, 15, 17};
    cout << solution.findMin(nums) << endl;

    return 0;
}
//
// Created by psycode on 2021/8/29.
//
// 33. 搜索旋转排序数组
// 整数数组 nums 按升序排列，数组中的值 互不相同 。
//
//在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，
// 使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
// 例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为[4,5,6,7,0,1,2] 。
//
//给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回-1。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 思路：直接二分查找
    int search(vector<int> &nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

    int binarySearch(vector<int> &nums, int target, int start, int end) {
        if (start >= end) {
            if (nums[start] == target) { return start; }
            return -1;
        }
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] >= target && nums[start] <= target) {
            return binarySearch(nums, target, start, mid - 1);
        }
        if (nums[mid] < nums[start] && (nums[mid] >= target || nums[start] <= target)) {
            return binarySearch(nums, target, start, mid - 1);
        }
        return binarySearch(nums, target, mid + 1, end);
    }
};

int main(int argc, const char *argv[]) {

    Solution solution;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << solution.search(nums, 0) << endl;
    cout << solution.search(nums, 3) << endl;

    return 0;
}

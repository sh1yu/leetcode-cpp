//
// Created by psycode on 2021/8/29.
//
// 使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
// 假设数组第一个位置值为first, 最后一个位置值为end，中间位置值为mid
// 这个问题的解决思路是：先查找mid，会有如下情形：
// 1. mid大于first,说明从first到mid都是有序的，无序位置为mid到end，继续查找；
// 2. mid小于first,说明无序位置为first到mid，继续二分查找。


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int searchUnOrderPosition(vector<int> &nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }

    int binarySearch(vector<int> &nums, int start, int end) {
        if (start >= end) {
            return end;
        }

        int mid = (start + end) / 2;
        if (nums[start] ==  nums[mid]) {
            return end;
        } else if (nums[start] < nums[mid]) {
            return binarySearch(nums, mid, end);
        } else {
            return binarySearch(nums, start, mid);
        }
    }
};

int main(int argc, const char *argv[]) {

    Solution s;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << s.searchUnOrderPosition(nums) << endl;

    nums = {5, 6, 7, 0, 1, 2};
    cout << s.searchUnOrderPosition(nums) << endl;

    return 0;
}


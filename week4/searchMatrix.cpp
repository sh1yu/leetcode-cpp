//
// Created by psycode on 2021/8/29.
//
// 74. 搜索二维矩阵
//
// 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
//
//每行中的整数从左到右按升序排列。
//每行的第一个整数大于前一行的最后一个整数。
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/search-a-2d-matrix
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 思路：直接按行列进行二分查找：二分查找到相应行，再二分查找到相应列
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = binarySearchRow(matrix, target, 0, matrix.size());
        if (row == -1) {
            return false;
        }
        int column = binarySearchColumn(matrix[row], target, 0, matrix[row].size());
        return column != -1;
    }

    int binarySearchRow(vector<vector<int>> &matrix, int target, int start, int end) {
        if (start >= matrix.size() || end <= 0) {
            return -1;
        }
        if (start >= end - 1) {
            return start;
        }
        int mid = (start + end) / 2;
        if (matrix[mid][0] == target) {
            return mid;
        }
        if (matrix[mid][0] < target) {
            return binarySearchRow(matrix, target, mid, end);
        }
        return binarySearchRow(matrix, target, start, mid);
    }

    int binarySearchColumn(vector<int> &row, int target, int start, int end) {
        if (start >= row.size() || end <= 0) {
            return -1;
        }
        if (start >= end - 1) {
            if (row[start] == target) {
                return start;
            }
            return -1;
        }
        int mid = (start + end) / 2;
        if (row[mid] == target) {
            return mid;
        }
        if (row[mid] < target) {
            return binarySearchColumn(row, target, mid, end);
        }
        return binarySearchColumn(row, target, start, mid);
    }
};

int main(int argc, const char *argv[]) {

    Solution solution;

    vector<vector<int>> matrix = {{1,  3,  5,  7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    cout << solution.searchMatrix(matrix, 3) << endl;
    cout << solution.searchMatrix(matrix, 1) << endl;
    cout << solution.searchMatrix(matrix, 20) << endl;
    cout << solution.searchMatrix(matrix, 23) << endl;
    cout << solution.searchMatrix(matrix, 7) << endl;
    cout << solution.searchMatrix(matrix, 60) << endl;
    cout << solution.searchMatrix(matrix, 0) << endl;
    cout << solution.searchMatrix(matrix, 24) << endl;
    cout << solution.searchMatrix(matrix, 69) << endl;

    return 0;
}
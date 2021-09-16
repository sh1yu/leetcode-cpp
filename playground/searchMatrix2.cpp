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
        int n = matrix.size() * matrix[0].size();
        int start = 0, end = n - 1;
        while (start <= end) {

            int mid = (end + start) / 2;
            int mid_row = mid / matrix[0].size();
            int mid_col = mid % matrix[0].size();

            if (matrix[mid_row][mid_col] == target) {
                return true;
            } else if (matrix[mid_row][mid_col] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
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

    vector<vector<int>> matrix2 = {{1, 1}};
    cout << solution.searchMatrix(matrix2, 2) << endl;

    return 0;
}
//
// Created by psycode on 2021/8/29.
//
// 874. 模拟行走机器人
// 机器人在一个无限大小的 XY 网格平面上行走，从点(0, 0) 处开始出发，面向北方。
// 该机器人可以接收以下三种类型的命令 commands ：
// - -2 ：向左转 90 度
// - -1 ：向右转 90 度
// - 1 <= x <= 9 ：向前移动 x 个单位长度
// 在网格上有一些格子被视为障碍物 obstacles 。第 i 个障碍物位于网格点 obstacles[i] = (xi, yi) 。
//
// 机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，但仍然可以继续尝试进行该路线的其余部分。
//
// 返回从原点到机器人所有经过的路径点（坐标为整数）的最大欧式距离的平方。（即，如果距离为 5 ，则返回 25 ）
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/walking-robot-simulation
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;
const int directions[4][2] = {{0,  1},
                              {1,  0},
                              {0,  -1},
                              {-1, 0}};

class Solution {
public:

    // 思路：回溯
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        vector<int> first = {0, 0};
        set<pair<int, int>> obstacleSet;
        for (vector<int> obstacle: obstacles) obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));
        return backtrack(commands, obstacleSet, first, NORTH, 0);
    }

    int backtrack(vector<int> &commands, set<pair<int, int>> &obstacleSet,
                  vector<int> &position, int direction, int ps) {
        // 没有任何新指令，直接返回0
        if (ps >= commands.size()) {
            //返回当前距离
            return position[0] * position[0] + position[1] * position[1];
        }

        int command = commands[ps];
        switch (command) {
            case -2:  //向左转 90 度, 保持在原地
                return backtrack(commands, obstacleSet, position, turnLeft(direction), ps + 1);
            case -1:  //向右转 90 度, 保持在原地
                return backtrack(commands, obstacleSet, position, turnRight(direction), ps + 1);
            default: //前进，计算新位置，是否有障碍物以及新距离
                move(position, direction, command, obstacleSet);
                int currDistance = position[0] * position[0] + position[1] * position[1];
                return max(currDistance, backtrack(commands, obstacleSet, position, direction, ps + 1));
        }
    }

    int turnLeft(int direction) {
        return (direction + 4 - 1) % 4;
    }

    int turnRight(int direction) {
        return (direction + 1) % 4;
    }

    void move(vector<int> &position, int direction, int step, set<pair<int, int>> &obstacleSet) {
        if (step == 0) {
            return;
        }
        int newX = position[0] + directions[direction][0];
        int newY = position[1] + directions[direction][1];
        if (obstacleSet.find(make_pair(newX, newY)) == obstacleSet.end()) {
            position[0] = newX;
            position[1] = newY;
            move(position, direction, step - 1, obstacleSet);
        }
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;

    vector<int> commands = {4, -1, 3};
    vector<vector<int>> obstacles = {};
    cout << solution.robotSim(commands, obstacles) << endl;

    commands = {4, -1, 4, -2, 4};
    obstacles = {{2, 4}};
    cout << solution.robotSim(commands, obstacles) << endl;

    return 0;
}
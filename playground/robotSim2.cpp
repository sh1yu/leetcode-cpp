//
// Created by psycode on 2021/9/3.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int robotSim2(vector<int> &commands, vector<vector<int>> &obstacles) {
        set<pair<int, int>> obstacleSet;
        for (vector<int> &o : obstacles) obstacleSet.insert(make_pair(o[0], o[1]));
        int distance = 0, x = 0, y = 0, dir = 0;
        int dirs[4][2] = {{0,  1},
                          {1,  0},
                          {0,  -1},
                          {-1, 0}};
        for (int &c : commands)
            if (c == -2) dir = dir == 0 ? 3 : dir - 1;
            else if (c == -1) dir = dir == 3 ? 0 : dir + 1;
            else {
                auto xy = dirs[dir];
                while (c-- > 0 && obstacleSet.find(make_pair(x + xy[0], y + xy[1])) == obstacleSet.end()) {
                    x += xy[0];
                    y += xy[1];
                }
                distance = max(distance, x * x + y * y);
            }
        return distance;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;

    vector<int> commands = {4, -1, 3};
    vector<vector<int>> obstacles = {};
    cout << solution.robotSim2(commands, obstacles) << endl;

    commands = {4, -1, 4, -2, 4};
    obstacles = {{2, 4}};
    cout << solution.robotSim2(commands, obstacles) << endl;

    return 0;
}
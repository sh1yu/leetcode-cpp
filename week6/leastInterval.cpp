//
// Created by psycode on 2021/9/14.
//
// 621. 任务调度器
// 给你一个用字符数组 tasks 表示的 CPU 需要执行的任务列表。其中每个字母表示一种不同种类的任务。
// 任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。在任何一个单位时间，CPU 可以完成一个任务，或者处于待命状态。
//
//然而，两个 相同种类 的任务之间必须有长度为整数 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
//
//你需要计算完成所有任务所需要的 最短时间 。
//
//
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/task-scheduler

#include <vector>
#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:

    // 官方的贪心写法.
    // 自己的思路是模拟时钟的方式往后走，记录每一个任务的ttl冷却时间，没有写出来
    // 官方写法是记录每一个任务的绝对完成时间，这样做的好处在于不用每次执行都更新全局的时间，且可以一下往后推多个时间单位
    // 时间复杂度O(|tasks||m|)
    // 空间复杂度O(m)
    int leastInterval(vector<char> &tasks, int n) {

        unordered_map<char, int> freq;
        for (char ch: tasks) {
            ++freq[ch];
        }

        // 任务总数
        int m = freq.size();
        vector<int> nextValid, rest;
        for (auto i = freq.begin(); i != freq.end(); i++) {
            nextValid.push_back(1);
            rest.push_back(i->second);
        }

        int time = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            ++time;

            // 找到当前剩余的任务中最近可执行的任务
            int minNextValid = INT_MAX;
            for (int j = 0; j < m; ++j) {
                if (rest[j]) {
                    minNextValid = min(minNextValid, nextValid[j]);
                }
            }
            time = max(time, minNextValid); //正常来说，time使用上面的++time依次往下执行就行了
                                            //这里做了一个优化，在minNextValid大于time时说明需要等待，因此直接推进等待的时间单位
                                            //不再依靠time依次往后加

            // 找到当前剩余的任务中哪个任务剩余的步数最多，这个任务（下标为best）就是下次处理的最佳任务
            int best = -1;
            for (int j = 0; j < m; ++j) {
                if (rest[j] && nextValid[j] <= time) {
                    if (best == -1 || rest[j] > rest[best]) {
                        best = j;
                    }
                }
            }
            nextValid[best] = time + n + 1; //最佳任务的下一次可执行时间更新
            --rest[best]; //最佳任务次数-1
        }

        return time;
    }
};

int main(int argc, const char *argv[]) {

    Solution s;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << s.leastInterval(tasks, 2) << endl;
    cout << s.leastInterval(tasks, 0) << endl;

    tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    cout << s.leastInterval(tasks, 2) << endl;
}
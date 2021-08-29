//
// Created by psycode on 2021/8/29.
//
// 455. 分发饼干
// 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
//
//对每个孩子 i，都有一个胃口值g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j]。
// 如果 s[j]>= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
// 你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/assign-cookies
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    //思路：贪心，先排序，然后每次都给当前小朋友满足条件的最小的尺寸
    //时间复杂度：O(nlogn)
    //空间复杂度：O(n)
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        auto g0 = g.begin();
        auto s0 = s.begin();
        int count = 0;
        while (g0 != g.end() && s0 != s.end()) {
            if (*s0 >= *g0) {
                count++;
                g0++;
            }
            s0++;
        }
        return count;
    }
};

int main(int argc, const char *argv[]) {

    Solution solution;

    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << solution.findContentChildren(g, s) << endl;

    g = {1, 2};
    s = {1, 2, 3};
    cout << solution.findContentChildren(g, s) << endl;

    g = {10, 9, 8, 7};
    s = {5, 6, 7, 8};
    cout << solution.findContentChildren(g, s) << endl;

    return 0;
}
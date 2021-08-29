//
// Created by psycode on 2021/8/29.
//

// 127. 单词接龙
// 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列：
//
//序列中第一个单词是 beginWord 。
//序列中最后一个单词是 endWord 。
//每次转换只能改变一个字母。
//转换过程中的中间单词必须是字典 wordList 中的单词。
//给你两个单词 beginWord 和 endWord 和一个字典 wordList ，找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。
// 如果不存在这样的转换序列，返回 0。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/word-ladder

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:

    // 记录每个单词到id的映射
    unordered_map<string, int> wordId;
    // 记录边
    vector<vector<int>> edge;
    int nodeNum = 0;

    // 初始化新增单词word的wordId和edge
    // 由于wordId从零开始自增，edge每次push，所以id是可以对应上的
    // 同时如果当前word已经在数组中存在了，不会重复添加
    void addWord(string &word) {
        if (!wordId.count(word)) {
            wordId[word] = nodeNum++;
            edge.emplace_back();
        }
    }

    // 添加边到单词word，同时将word的每一个字符都转换为*,并添加节点和边
    void addEdge(string &word) {
        addWord(word);
        int id1 = wordId[word];
        for (char &it : word) {
            char tmp = it;
            it = '*';
            // 添加包含*的节点（可能之前已经添加过，这里一样能处理）
            addWord(word);
            // 添加包含*的节点后取出其id，添加边
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }
    }

    // 思路：没有思路。看了官方题解知道可以构造图然后求最短路径来完成，
    // 但是构建图上没有什么思绪。拷贝一下官方题解，慢慢消化。
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

        // 构建候选词的点和边
        for (string &word : wordList) {
            addEdge(word);
        }
        addEdge(beginWord);
        if (!wordId.count(endWord)) {
            return 0;
        }

        // dis存储每个节点到begin节点的距离
        vector<int> dis(nodeNum, INT_MAX);
        int beginId = wordId[beginWord], endId = wordId[endWord];
        dis[beginId] = 0;

        // queue用于广度优先搜索
        queue<int> que;
        que.push(beginId);
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            if (x == endId) {
                // 找到最终节点，返回距离
                return dis[endId] / 2 + 1;
            }
            // 不是最终节点，遍历节点的边，更新其到begin的距离，并等待下次广度优先搜索到其相邻的点
            for (int &it : edge[x]) {
                if (dis[it] == INT_MAX) {
                    dis[it] = dis[x] + 1;
                    que.push(it);
                }
            }
        }
        return 0;
    }
};

int main(int argc, const char *argv[]) {

    Solution solution;

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << solution.ladderLength(beginWord, endWord, wordList) << endl;

    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << solution.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}
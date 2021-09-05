//
// Created by psycode on 2021/9/3.
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
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:

    int ladderLength2(string beginWord, string endWord, vector<string> &wordList) {


        if (beginWord == endWord) {
            return 1;
        }

        unordered_set<string> wordSet;
        for (string &s:wordList) {
            wordSet.emplace(s);
        }
        wordSet.erase(beginWord);

        unordered_map<string, int> dis;
        dis[beginWord] = 1;
        queue<string> que;
        que.push(beginWord);
        while (!que.empty()) {
            string x = que.front();
            que.pop();
            if (x == endWord) {
                return dis[x];
            }

            for (int i = 0; i < x.length(); i++) {
                int curr_dis = dis[x];
                char c0 = x[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    x[i] = c;
                    if (wordSet.find(x) != wordSet.end()) {
                        wordSet.erase(x);
                        dis[x] = curr_dis + 1;
                        que.push(x);
                    }
                }
                x[i] = c0;
            }

//            for (string &s: wordList) {
//                if (s.length() != x.length()) {
//                    continue;
//                }
//                if (dis.find(s) != dis.end()) {
//                    continue;
//                }
//                int diff_count = 0;
//                for (int i = 0; i < s.length(); i++) {
//                    if (s[i] != x[i]) {
//                        diff_count++;
//                        if (diff_count >= 2) {
//                            break;
//                        }
//                    }
//                }
//                if (diff_count != 1) {
//                    continue;
//                }
//                dis[s] = dis[x] + 1;
//                que.push(s);
//            }
        }
        return 0;
    }
};

int main(int argc, const char *argv[]) {

    Solution solution;

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << solution.ladderLength2(beginWord, endWord, wordList) << endl;

    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << solution.ladderLength2(beginWord, endWord, wordList) << endl;

    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot", "cog", "dot", "dog", "hit", "lot", "log"};
    cout << solution.ladderLength2(beginWord, endWord, wordList) << endl;

    return 0;
}

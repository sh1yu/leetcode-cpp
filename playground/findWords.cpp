//
// Created by psycode on 2021/9/16.
//
// 212. 单词搜索 II
// 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。
//
//单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/word-search-ii

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

struct TrieNode {
    string word;
    unordered_map<char, TrieNode *> children;

    TrieNode() {
        this->word = "";
    }
};

void insertTrie(TrieNode *root, const string &word) {
    TrieNode *node = root;
    for (auto c : word) {
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->word = word;
}

class Solution {
public:

    int dirs[4][2] = {{1,  0},
                      {-1, 0},
                      {0,  1},
                      {0,  -1}};

    void dfs(vector<vector<char>> &board, int x, int y, TrieNode *root, set<string> &res) {
        char ch = board[x][y];
        if (!root->children.count(ch)) {
            return;
        }
        root = root->children[ch];
        if (root->word.size() > 0) {
            res.insert(root->word);
            root->word = "";
        }

        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if (board[nx][ny] != '#') {
                    dfs(board, nx, ny, root, res);
                }
            }
        }
        board[x][y] = ch;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        TrieNode *root = new TrieNode();
        set<string> res;
        vector<string> ans;

        for (auto &word: words) {
            insertTrie(root, word);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, res);
            }
        }
        for (auto &word: res) {
            ans.emplace_back(word);
        }
        return ans;
    }
};

int main(int argc, const char *argv[]) {

    Solution s;

    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                  {'e', 't', 'a', 'e'},
                                  {'i', 'h', 'k', 'r'},
                                  {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};

    vector<string> res = s.findWords(board, words);

    for (string &r: res) {
        cout << r << " ";
    }
    cout << endl;

}
//
// Created by psycode on 2021/9/5.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        auto p = s.find(' ');
        while (p  != string::npos) {
            s.replace(p, 1, "%20");
            p = s.find(' ', p+1);
        }
        return s;
    }
};

int main(int argc, const char *argv[]) {
    Solution solution;

    string s = "we are happy.";
    cout << solution.replaceSpace(s) << endl;

    return 0;
}
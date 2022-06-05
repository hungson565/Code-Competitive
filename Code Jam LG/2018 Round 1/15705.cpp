// https://codejam.lge.com/problem/15705

// build: g++ -o 15705 15705.cpp -std=c++11 && 15705

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*

TC:

ABCD
5 5
ACDBE
ABCED
ACCEE
ACHDF
ACBCE

*/

string st(char c) {
    return string(1, c);
}

void solve() {
    string s;
    cin >> s;
    int n, m;
    cin >> n;
    cin >> m;

    vector<string> data;
    string e;
    for (int i = 0; i < n; i++) {
        cin >> e;
        data.push_back(e);
    }

    int N = s.size();

    if (N == 0) {
        cout << "1" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // right
            {
                string right;
                for (int k = 0; k < N && j + k < m; k++) {
                    right += st(data[i][j + k]);
                }
                // cout << "i: " << i << ", j: " << j << ", right: " << right << endl;
                if (right == s) {
                    cout << "1" << endl;
                    return;
                }
            }
            // left
            {
                string left;
                for (int k = 0; k < N && j - k >= 0; k++) {
                    left += st(data[i][j - k]);
                }
                if (left == s) {
                    cout << "1" << endl;
                    return;
                }
            }
            // down
            {
                string down;
                for (int k = 0; k < N && i + k < n; k++) {
                    down += st(data[i + k][j]);
                }
                if (down == s) {
                    cout << "1" << endl;
                    return;
                }
            }
            // up
            {
                string up;
                for (int k = 0; k < N && i - k >= 0; k++) {
                    up += st(data[i - k][j]);
                }
                if (up == s) {
                    cout << "1" << endl;
                    return;
                }
            }
            // diag left -> right
            {
                string diag_left;
                for (int k = 0; k < N && i + k < n && j + k < m; k++) {
                    diag_left += st(data[i + k][j + k]);
                }
                // cout << "i: " << i << ", j: " << j << ", diag_left: " << diag_left << endl;
                if (diag_left == s) {
                    cout << "1" << endl;
                    return;
                }
            }
            // diag right - > left
            {
                string diag_right;
                for (int k = 0; k < N && i + k < n && j - k >= 0; k++) {
                    diag_right += st(data[i + k][j - k]);
                }
                if (diag_right == s) {
                    cout << "1" << endl;
                    return;
                }
            }
            // diag left -> right
            {
                string diag_left;
                for (int k = 0; k < N && i - k >= 0 && j + k < m; k++) {
                    diag_left += st(data[i - k][j + k]);
                }
                // cout << "i: " << i << ", j: " << j << ", diag_left: " << diag_left << endl;
                if (diag_left == s) {
                    cout << "1" << endl;
                    return;
                }
            }

            // diag right - > left
            {
                string diag_right;
                for (int k = 0; k < N && i - k >= 0 && j - k >= 0; k++) {
                    diag_right += st(data[i - k][j - k]);
                }
                if (diag_right == s) {
                    cout << "1" << endl;
                    return;
                }
            }
        }
    }

    cout << "0" << endl;
}

int main() {
    solve();
}

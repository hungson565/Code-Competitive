// https://codeforces.com/contest/1566/problem/C
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

int T;
int n;
string s;

/*

4
7
0101000
1101100
5
01100
10101
2
01
01
6
000000
111111

*/

void solve() {
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    vector<int> val(n, 0);
    for (int i = 0; i < n; i++) {
        if (s1[i] == '0' && s2[i] == '0') {
            val[i] = 1;
        } else if (s1[i] == '0' && s2[i] == '1') {
            val[i] = 2;
        } else if (s1[i] == '1' && s2[i] == '0') {
            val[i] = 2;
        } else {
            val[i] = 0;
        }
    }

    // for (int e : val) {
    //     cout << e << " ";
    // }
    // cout << endl;

    for (int i = 0; i < n; i++) {
        if (val[i] == 0) {
            if (i == 0) {
                if (n > 1 && val[i + 1] == 1) {
                    val[i + 1] = 2;
                }
            } else if (i == n - 1) {
                if (n > 1 && val[i - 1] == 1) {
                    val[i - 1] = 2;
                }
            } else {
                if (val[i + 1] == 1 && val[i - 1] == 1) {
                    val[i - 1] = 2;
                } else if (val[i + 1] == 1) {
                    val[i + 1] = 2;
                } else if (val[i - 1] == 1) {
                    val[i - 1] = 2;
                }
            }
        }
    }

    // cout << "after: " << endl;
    // for (int e : val) {
    //     cout << e << " ";
    // }
    // cout << endl;

    int ans = 0;
    for (auto e : val) {
        ans += e;
    }

    cout << ans << endl;

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

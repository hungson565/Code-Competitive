// https://codeforces.com/contest/1567/problem/C
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

5
100
12
8
2021
10000

*/

void solve() {

    int n;
    cin >> n;

    int64_t ans = 0;

    int64_t n1 = 0;
    int64_t n2 = 0;

    string s = to_string(n);

    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) {
            n1 = n1 * 10 + (s[i] - '0');
        } else {
            n2 = n2 * 10 + (s[i] - '0');
        }
    }

    ans = (n1 + 1) * (n2 + 1) - 2;
    cout << ans << endl;
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

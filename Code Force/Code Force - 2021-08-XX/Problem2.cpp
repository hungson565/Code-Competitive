// https://codeforces.com/contest/1559/problem/A
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int T;
int a, b, c;

/*

7
6 2 4
2 3 1
2 4 10
5 3 4
1 3 2
2 5 4
4 3 2

*/


void solve() {

    cin >> a;
    cin >> b;
    cin >> c;

    int d = abs(a - b);
    int n = 2 * d;
    int ans = -1;
    if (c > n || a > n || b > n) {
        cout << "-1" << endl;
        return;
    }

    int ans1 = c - d;
    int ans2 = c + d;

    if (ans1 > 0 && ans1 <= n) {
        ans = ans1;
    }

    if (ans2 > 0 && ans2 <= n) {
        ans = ans2;
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

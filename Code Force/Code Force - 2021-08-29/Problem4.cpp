// https://codeforces.com/contest/1559/problem/A
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

int T;
int k;

/*
7
11
14
5
4
1
2
1000000000

*/


void solve() {
    cin >> k;

    int K = sqrt(k);
    int a = 0;

    // square: (a + 1) --> find a???
    // K * K == k -> k = (a + 1)^2
    if (K * K == k) {
        a = K - 1;
    } else {
        a = K;
    }

    int b = a * a + a + 1;

    if (k == b) {
        cout << a + 1 << " " << a + 1 << endl;
        return;
    }

    if (k < b) {
        cout << a + 1 - (b - k) << " " << a + 1 << endl;
        return;
    }

    if (k > b) {
        cout << a + 1 << " " << a + 1 - (k - b) << endl;
        return;
    }

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

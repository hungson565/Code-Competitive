// https://codeforces.com/contest/1567/problem/D
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
6
97 2
17 1
111 4
100 2
10 9
999999 3

*/


void solve() {
    int s;
    int n;
    cin >> s;
    cin >> n;
    cout << s - (n - 1) << " ";
    for (int i = 0; i < n - 1; i++) {
        cout << 1 << " ";
    }
    cout << endl;
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

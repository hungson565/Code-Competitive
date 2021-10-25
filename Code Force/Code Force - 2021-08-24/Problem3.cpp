// https://codeforces.com/contest/1561/problem/C
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
int n;

/*
2
1
1 42
2
3 10 15 8
2 12 11

*/


void solve() {
    cin >> n;
    int val;
    int m = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            scanf("%d", &val);
            if (m + j < val) {
                m = val - j + 1;
                cout << "i: " << i << ", j: " << j << ", val: " << val << ", m: " << m << endl;
            }
        }
    }

    cout << m << endl;

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

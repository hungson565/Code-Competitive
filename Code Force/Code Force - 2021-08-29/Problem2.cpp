// https://codeforces.com/contest/1556/problem/B
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

int64_t T;
int64_t n;
string s;

/*

5
3
6 6 1
1
9
6
1 1 1 2 2 2
2
8 6
6
6 2 3 4 5 1

*/

void solve() {

    int64_t n;
    cin >> n;
    vector<int64_t> data; // contains index of odd element
    int64_t val;
    for (int64_t i = 0; i < n; i++) {
        scanf("%d", &val);
        if (val % 2 == 1) {
            data.push_back(i);
        }
    }

    int64_t n_odd = data.size();
    if (n % 2 == 0 && n_odd != n / 2) {
        cout << "-1" << endl;
        return;
    }
    if (n % 2 == 1 && n_odd != n / 2 && n_odd != (n / 2 + 1)) {
        cout << "-1" << endl;
        return;
    }

    if (n % 2 == 0) {
        int64_t result1 = 0;
        for (int64_t i = 0; i < n_odd; i++) {
            result1 += abs(2 * i + 1 - data[i]);
        }
        int64_t result2 = 0;
        for (int64_t i = 0; i < n_odd; i++) {
            result2 += abs(2 * i - data[i]);
        }
        int64_t result = min(result2, result1);
        cout << result << endl;
    } else {
        if (n_odd == n / 2) {
            int64_t result = 0;
            for (int64_t i = 0; i < n_odd; i++) {
                result += abs(2 * i + 1 - data[i]);
                
            }
            cout << result << endl;
        } else {
            int64_t result = 0;
            for (int64_t i = 0; i < n_odd; i++) {
                result += abs(2 * i - data[i]);
                
            }
            cout << result << endl;
        }
    }

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

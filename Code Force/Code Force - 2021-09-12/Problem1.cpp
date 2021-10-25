// https://codeforces.com/contest/1566/problem/0
// A. Median Maximization
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int T;
int a, b;

/*

8
1 5
2 5
3 5
2 1
7 17
4 14
1 1000000000
1000000000 1

*/


void solve() {
    
    int n;
    int s;
    cin >> n;
    cin >> s;
    int num = 0;
    if (n % 2 == 1) {
        num = (n - 1) / 2 + 1;
    } else {
        num = n / 2 + 1;
    }
    int ans = s / num;
    // cout << "ans: " << ans << endl;
    cout << ans << endl;
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

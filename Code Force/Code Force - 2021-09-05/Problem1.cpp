// https://codeforces.com/contest/1567/problem/A
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

4
1
U
2
LR
5
LRDLR
6
UUUUUU

*/


void solve() {
    
    int n;
    string s;
    cin >> n;
    cin >> s;
    string ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            ans += 'D';
        } else if (s[i] == 'D') {
            ans += 'U';
        } else {
            ans += s[i];
        }
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

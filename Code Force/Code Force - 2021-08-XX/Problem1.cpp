// https://codeforces.com/contest/1560/problem/0
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
int n;

/*

10
1
2
3
4
5
6
7
8
9
1000

*/


void solve() {
    cin >> n;
	
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans++;
        while (ans % 3 == 0 || ans % 10 == 3) {
            ans++;
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

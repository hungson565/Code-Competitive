// https://codeforces.com/contest/1562/problem/E
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
string s;

/*
7
5
acbac
8
acabacba
12
aaaaaaaaaaaa
10
abacabadac
8
dcbaabcd
3
cba
6
sparky

*/


void solve() {
    cin >> n;
	cin >> s;

	// dp[i]: answer of string that end with s[i]
    vector<int> dp(n + 1, 0);
	dp[0] = n;
	
	for (int i = 1; i < n; i++) {
		int val = 0;
		for (int j = 0; j < i; j++) {
			if (s[i] > s[j]) {
				val = max(val, dp[j] + (n - i));
			}
			else
			{
				val = max(val, (n - i));
			}
				
		}
		dp[i] = val;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << "i: " << dp[i] << endl;
	// }

	cout << ans << endl;

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

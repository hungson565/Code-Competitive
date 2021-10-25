// https://codejam.lge.com/problem/17137
// build: 

// 
/*

g++ -o NumberGame NumberGame.cpp -std=c++11 && NumberGame

TC:

4
1
3
2
3 3
3
1 2 3
6
95 96 97 98 99 100


*/

#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <deque>
#define ll long long

void cal() {
    int n;
    vector<int> x;
    cin >> n;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        x.push_back(val);
    }
    sort(x.begin(), x.end());

    // dp[n][x]: value: from index n, value at index n is x
    // Need to calculate dp[0][0] + dp[0][1] + ... + dp[0][x1 - 1];
    vector<vector<int64_t>> dp(300, vector<int64_t>(300, 0));
    // init values
    // dp[n - 1][0] = x[n - 1];
    // dp[n - 1][1] = x[n - 1] - 1;
    // dp[n - 1][x[n - 1] - 1] = x[n - 1] - (x[n - 1] - 1) = 1;
    for (int i = 0; i <= x[n - 1] - 1; i++) {
        dp[n - 1][i] = 1;
    }

    // cout << "==================================" << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < x[i]; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "==================================" << endl;

    for (int i = n - 2; i >= 0; i--) {
        // cal dp[i][x], x : 0 -> x[i] - 1
        for (int j = 0; j <= x[i] - 1; j++) {
            for (int k = j; k <= x[i + 1] - 1; k++) {
                dp[i][j] = dp[i][j] + dp[i + 1][k];
            }
            dp[i][j] = dp[i][j] % 1000000007;
        }
    }

    int64_t ans = 0;
    // ans = dp[0][0] + dp[0][1] + .. + dp[0][x[0] - 1]
    for (int i = 0; i <= x[0] - 1; i++) {
        ans = (ans + dp[0][i]) % 1000000007;
    }

    ans = (ans * n) % 1000000007;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        cal();
    }
    return 0;
}

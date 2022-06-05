#include <bits/stdc++.h>
#include <math.h>

using namespace std;

#define int int64_t

/*

5
ABA
BBB
BCCB
CLCD
ALBERT

*/

bool isAlbus(char c) {
    // ALBERT
    for (auto e : "ALBERT") {
        if (e == c) {
            return true;
        }
    }
    return false;
}

bool isAlice(char c) {
    // ALICE
    for (auto e : "ALICE") {
        if (e == c) {
            return true;
        }
    }
    return false;
}

int calVal(char c, bool albusTurn) {
    if (albusTurn) {
        if (isAlbus(c)) {
            return 2;
        } else {
            return 0;
        }
    } else {
        if (isAlice(c)) {
            return -1;
        } else {
            return 0;
        }
    }
}

bool play(string& s, int i, int j, int k, vector<vector<vector<bool>>>& dp, vector<vector<vector<bool>>>& flag) {
    // cout << "i: " << i << ", j: " << j << ", k: " << k << endl;
    int n = s.size();
    bool albusTurn = true;

    int len = j - i + 1;

    if ((n - len) % 2 == 1) {
        albusTurn = false;
    }

    if (flag[i][j][k+ 100]) {
        return dp[i][j][k+ 100];
    }

    if (len <= 0) {
        return true;
    }

    if (len == 1) {
        if (calVal(s[i], albusTurn) == k) {
            flag[i][j][k+ 100] = true;
            dp[i][j][k + 100] =true;
			return dp[i][j][k + 100];
        } else {
            dp[i][j][k + 100] =false;
			return dp[i][j][k + 100];
        }
    }

    if (albusTurn) {
        if (isAlbus(s[i])) {
            flag[i][j][k+ 100] = true;
            dp[i][j][k + 100] = play(s, i + 1, j, k - calVal(s[i], albusTurn), dp,flag);
			return dp[i][j][k + 100];
        } else {
            flag[i][j][k+ 100] = true;
            dp[i][j][k + 100] = play(s, i, j - 1, k - calVal(s[j], albusTurn), dp,flag);
			return dp[i][j][k + 100];
        }
    } else {
        flag[i][j][k+ 100] = true;
        dp[i][j][k + 100] = play(s, i + 1, j, k - calVal(s[i], albusTurn), dp,flag) | play(s, i, j - 1, k - calVal(s[j], albusTurn), dp,flag);
		return dp[i][j][k + 100];
    }

    return true;
}

void solve() {

    string s;
    cin >> s;

    int n = s.size();

    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(400, false)));
    vector<vector<vector<bool>>> flag(n, vector<vector<bool>>(n, vector<bool>(400, false)));

    int ans = -1;
    for (int i = 1; i <= 300; i++) {
        if (play(s, 0, n - 1, i, dp, flag)) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    

    while (T > 0) {
        solve();
        T--;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int T;
string s;

// ALBERT
// ALICE

int score_ALBERT(int i) {
	char c = s[i];
	if (c == 'A' || c == 'L' || c == 'B' || c == 'E' || c == 'R' || c == 'T') {
		return 2;
	}
	return 0;
}

int score_ALICE(int i) {
	char c = s[i];
	if (c == 'A' || c == 'L' || c == 'I' || c == 'C' || c == 'E') {
		return 1;
	}
	return 0;
}

int dp[150][150][310];

// play(int m, int i, int j)
// return minimum value that > m in range (i, j)
// need to calculate play(0, 0, n - 1)

int play(int m, int i, int j) {
	
	if (dp[i][j][m + 150] != -1) {
		return dp[i][j][m + 150];
	}
	
	if (i == j) {
		if (score_ALBERT(i) > m) {
//			cout << "----value with i: " << i << ", j: " << j << ", IS:  " << score_ALBERT(i)  << endl;
			dp[i][j][m + 150] = score_ALBERT(i);
		} else {
//			cout << "----value with i: " << i << ", j: " << j << ", IS:  " << -1  << endl;

			dp[i][j][m + 150] = -99999;
		}
		return dp[i][j][m + 150];
	}
	
	if (i == j - 1) {
// 		int v1 = score_ALBERT(i) - score_ALICE(j);
// 		int v2 = score_ALBERT(j) - score_ALICE(i);
// 		int v = -99999;
// 		if (v1 > m) {
// //			cout << "***, v1: " << v1 << ", m: " << m << endl;
// 			v = v1;
// 		}
// 		if (v2 > m && v2 < v1) {
// 			v = v2;
// 		}
// 		dp[i][j][m + 150] = v;
// 		return dp[i][j][m + 150];

		int v = -99999;
		if (score_ALBERT(i) == 2) { // ALBERT takes i
			v = score_ALBERT(i) - score_ALICE(j);
		} else  { // // ALBERT takes j
			v = score_ALBERT(j) - score_ALICE(i);
		}
		dp[i][j][m + 150] = v;
		if (dp[i][j][m + 150] <= m) {
			dp[i][j][m + 150] = -99999;
		}
		return dp[i][j][m + 150];
	}
	
	int value = -99999;
	// case 1: ALBERT get j, remain: i ... j - 1
	int value1;
	int value2;
// 	if (score_ALBERT(i) == 2) {
// //		cout << "x1" << endl;
// 		value1 = 2 - score_ALICE(j) + play(m - (2 - score_ALICE(j)), i + 1, j - 1);
// 		value2 = 2 - score_ALICE(i + 1) + play(m - (2 - score_ALICE(i + 1)), i + 2, j);
// 	} else if (score_ALBERT(j) == 2) {
// //		cout << "x2" << endl;
// 		value1 = 2 - score_ALICE(j - 1) + play(m - (2 - score_ALICE(j - 1)), i , j - 2);
// 		value2 = 2 - score_ALICE(i) + play(m - (2 - score_ALICE(i)), i  + 1, j - 1);
// 	} else {
// //		cout << "x3" << endl;
// 		value1 = 0 - score_ALICE(j - 1) + play(m - (0 - score_ALICE(j - 1)), i , j - 2);
// 		value2 = 0 - score_ALICE(i) + play(m - (0 - score_ALICE(i)), i  + 1, j - 1);
// 	}
	// cout << "value1: " << value1 << ", value2: " << value2 << endl;

	if (score_ALBERT(i) == 2) { // ALBERT takes i
//		cout << "x1" << endl;
		value1 = 2 - score_ALICE(j) + play(m - (2 - score_ALICE(j)), i + 1, j - 1);
		value2 = 2 - score_ALICE(i + 1) + play(m - (2 - score_ALICE(i + 1)), i + 2, j);
	} else  { // // ALBERT takes j
//		cout << "x2" << endl;
		value1 = score_ALBERT(j) - score_ALICE(j - 1) + play(m - (score_ALBERT(j) - score_ALICE(j - 1)), i , j - 2);
		value2 = score_ALBERT(j) - score_ALICE(i) + play(m - (score_ALBERT(j) - score_ALICE(i)), i  + 1, j - 1);
	}

	if (value1 > m) {
		value = value1;
	}
	if (value2 > m && value2 < value1) {
		value = value2;
	}
	
	dp[i][j][m + 150] = value;

	// if (dp[i][j][m + 150] < -1) {
	// 	dp[i][j][m + 150] = INT_MIN;
	// }

//	cout << "-----value with i: " << i << ", j: " << j << ", IS:  " << value  << endl;

	return dp[i][j][m + 150];
}

void solve() {
	memset(dp, -1, sizeof(dp));
	// for (int i = 0; i < 160; i++) {
	// 	for (int j = 0; j < 160; j++) {
	// 		for (int t = 0; t < 600; t++) {
	// 			dp[i][j][t] = -1;
	// 		}
	// 	}
	// }
	cin >> s;
	int n = (int)s.size();
	int result = 0;
	result = play(0, 0, n - 1);
	if (result <= 0) {
		result = -1;
	}
	cout << result << endl;
}


int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
	return 0;
}


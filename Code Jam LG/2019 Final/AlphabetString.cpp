// https://codejam.lge.com/problem/17464

// build: g++ -o AlphabetString AlphabetString.cpp -std=c++11 && AlphabetString

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
int N;

/*



TC:

4
AAA
ABCBA
ABABAB
ABCXYZABC

*/

void solve() {
    // input
	string s;
    cin >> s;
    int n = s.size();
    char start = s[0];
    int count = 1;
    int64_t ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i + 1] > s[i]) {
            start = s[i + 1];
            count++;
        } else {
            start = s[i + 1];
            ans += count * (count + 1) / 2;
            count = 1;
        }
    }
    ans += count * (count + 1) / 2;
    cout << ans << endl;

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

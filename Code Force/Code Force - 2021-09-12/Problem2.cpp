// https://codeforces.com/contest/1566/problem/B
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

int T;
int n;
string s;

/*

6
01
1111
01100
101
0000
01010

*/

void solve() {

    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (count != 0) {
          ans += 1;
          count = 0;
        }
      } else {
        count++;
      }

//      cout << "i: " << i << ", count: " << count << endl;

    }

    if (count != 0) {
      ans += 1; 
    }

    if (ans > 2) {
      ans = 2;
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

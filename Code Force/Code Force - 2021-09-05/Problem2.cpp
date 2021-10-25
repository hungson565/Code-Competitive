// https://codeforces.com/contest/1567/problem/B
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

5
1 1
2 1
2 0
1 10000
2 10000

*/

int computeXOR(int n)
{
   
  // If n is a multiple of 4
  if (n % 4 == 0)
    return n;
 
  // If n%4 gives remainder 1
  if (n % 4 == 1)
    return 1;
 
  // If n%4 gives remainder 2
  if (n % 4 == 2)
    return n + 1;
 
  // If n%4 gives remainder 3
  return 0;
}

void solve() {

    int a;
    int b;
    cin >> a;
    cin >> b;
    int ans = 0;

    ans += a;

    int sum = computeXOR(a - 1);

    int B = sum ^ b;
    // cout << "B: " << B << endl;
    if (B == 0) {
        cout << ans << endl;
    } else if (B != a) {
        ans++;
        cout << ans << endl;
    } else {
        ans += 2;
        cout << ans << endl;
    }

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

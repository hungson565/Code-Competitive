// https://codeforces.com/contest/1561/problem/A
#include <stdlib.h>
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
1 1
999999999 1000000000
8 26
1 999999999

*/


void solve() {
    
    cin >> a;
    cin >> b;

    int t = 0;
    if (b % 2 == 0) {
        t = b / 2;
    } else {
        t = b / 2 + 1;
    }

    int A;
    int B;

    if (a >= t) {
        A = a;
        B = b;
        if (B - A >= A) {
            cout << B - A - 1 << endl;
        } else {
            cout << B - A << endl;
        }
        
    } else {
        A = t;
        B = b;
        cout << t - 1 << endl;
    }




}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

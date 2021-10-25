// https://codeforces.com/contest/1556/problem/A
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int T;
int c, d;

/*

6
1 2
3 5
5 3
6 6
8 0
0 0

*/


void solve() {
    
    cin >> c;
    cin >> d;

    if (c == 0 && d == 0) {
        cout << "0" << endl;
        return;
    }

    if (c == d) {
        cout << "1" << endl;
        return;
    }
    if ((c - d) % 2 != 0) {
        cout << "-1" << endl;
        return;
    }

    cout << "2" << endl;
    return;

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

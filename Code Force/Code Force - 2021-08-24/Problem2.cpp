// https://codeforces.com/contest/1561/problem/B
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
int a, b;

/*

3
2 1
1 1
0 5

*/


void solve() {

    cin >> a;
    cin >> b;

    set<int> ans;

    int n = a + b;
    if (n % 2 == 0) {
        int a_init = n / 2;
        int b_init = n / 2;
        int x; int y; // a_init - x + y = a; b_init - y + x = b

        // x >= 0; x <= a_init
        // y >= 0; y <= b_init
        // y = b_init + x - b

        for (x = 0; x <= a_init; x++) {
            y = b_init + x - b;
            if (y >= 0 && y <= b_init) {
                ans.insert(x + y);
            }
        }

    } else {
        {
            int a_init = n / 2 + 1;
            int b_init = n / 2;
            int x; int y; // a_init - x + y = a; b_init - y + x = b

            // x >= 0; x <= a_init
            // y >= 0; y <= b_init
            // y = b_init + x - b

            for (x = 0; x <= a_init; x++) {
                y = b_init + x - b;
                if (y >= 0 && y <= b_init) {
                    ans.insert(x + y);
                }
            }
        }

        {
            int a_init = n / 2;
            int b_init = n / 2 + 1;
            int x; int y; // a_init - x + y = a; b_init - y + x = b

            // x >= 0; x <= a_init
            // y >= 0; y <= b_init
            // y = b_init + x - b

            for (x = 0; x <= a_init; x++) {
                y = b_init + x - b;
                if (y >= 0 && y <= b_init) {
                    ans.insert(x + y);
                }
            }
        }
        
    }

    cout << ans.size() << endl;
    for (auto e : ans) {
        cout << e << " ";
    }
    cout << endl;

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

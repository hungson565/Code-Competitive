// https://codejam.lge.com/problem/17122
// build: 

// 
/*

g++ -o Chess Chess.cpp -std=c++11 && Chess

4
A1 17
A1 1
B3 21
G5 40

*/

#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <deque>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    // false: black, true: white
    vector<bool> m(65, false);
    vector<int> index = {2, 4, 6, 8, 9, 11, 13, 15};
    for (int i = 0; i < 4; i++) {
        for (auto& e : index) {
            m[e] = true;
            e += 16;
        }
    }

    // for (int i = 1; i <= 64; i++) {
    //     cout << m[i];
    //     if (i % 8 == 0) {
    //         cout << endl;
    //     }
    // }

    cin >> t;
    while (t--) {
        string s1;
        int val2;
        cin >> s1;
        cin >> val2;
        int val1;
        val1 = (s1[1] - '0' - 1) * 8 + (s1[0] - 'A') + 1;

        // cout << "val1: " << val1 << endl;
        // cout << "val2: " << val2 << endl;

        // val1, val same color or NOT
        if (m[val1] == m[val2]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}

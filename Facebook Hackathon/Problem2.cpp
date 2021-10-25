// https://codeforces.com/contest/1562/problem/B
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

7
3
237
5
44444
3
221
2
35
3
773
1
4
30
626221626221626221626221626221

*/

bool checkPrime(int val) {
    int s = 0;
    for (int i = 2; i <= sqrt(val); i++) {
        if (val % i == 0) {
            return false;
        }
    }
    return true;
}


void solve() {

    cin >> n;
    cin >> s;
    char found_c;
    bool found = false;
    int num_2 = 0;
    int num_3 = 0;
    int num_5 = 0;
    int num_7 = 0;
    for (auto c : s) {
        if (c != '2' && c != '3' && c != '5' && c != '7') {
            found_c = c;
            found = true;
            break;
        }
        if (c == '2') {
            num_2++;
        } else if (c == '3') {
            num_3++;
        } else if (c == '5') {
            num_5++;
        } else {
            num_7++;
        }
    }
    if (found) {
        cout << 1 << endl;
        cout << found_c << endl;
        return;
    }

    if (num_2 >= 2) {
        cout << 2 << endl;
        cout << 22 << endl;
        return;
    }

    if (num_3 >= 2) {
        cout << 2 << endl;
        cout << 33 << endl;
        return;
    }

    if (num_5 >= 2) {
        cout << 2 << endl;
        cout << 55 << endl;
        return;
    }

    if (num_7 >= 2) {
        cout << 2 << endl;
        cout << 77 << endl;
        return;
    }

    // size of s = 1, 2, 3, 4

    if (n == 1) {
        cout << 1 << endl;
        cout << s << endl;
        return;
    }

    if (n == 2) {
        cout << 2 << endl;
        cout << s << endl;
        return;
    }

    if (n == 4) {
        string s1 = string(1, s[0]) + string(1, s[1]);
        string s2 = string(1, s[0]) + string(1, s[2]);
        string s3 = string(1, s[0]) + string(1, s[3]);
        string s4 = string(1, s[1]) + string(1, s[2]);
        string s5 = string(1, s[1]) + string(1, s[3]);
        string s6 = string(1, s[2]) + string(1, s[3]);
        vector<string> v = {s1, s2, s3, s4, s5, s6};

        for (auto e : v) {
            // cout << "e: " << e << endl;
            int val = stoi(e);
            // cout << "e2: " << e << endl;
            if (!checkPrime(val)) {
                cout << 2 << endl;
                cout << val << endl;
                break;
            }
        }
        return;
    }

    // n == 3
    string s1 = string(1, s[0]) + string(1, s[1]);
    string s2 = string(1, s[0]) + string(1, s[2]);
    string s3 = string(1, s[1]) + string(1, s[2]);
    vector<string> v = {s1, s2, s3};

    for (auto e : v) {
        // cout << "e: " << e << endl;
        int val = stoi(e);
        // cout << "e2: " << e << endl;
        if (!checkPrime(val)) {
            cout << 2 << endl;
            cout << val << endl;
            break;
        }
    }

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

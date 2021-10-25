#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int T;

int n;

void solve() {
    cin >> n;
    vector<string> in;
    vector<string> out;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        in.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        cin >> s;
        out.push_back(s);
    }

    sort(in.begin(), in.end());
    sort(out.begin(), out.end());

    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (in[i] != out[i]) {
            ans = false;
            break;
        }
    }

    if (ans) {
        cout << "NOT CHEATER" << endl;
    } else {
        cout << "CHEATER" << endl;
    }

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/*
3
3 3
10 100 200
7 3
28 11 17 19 21 22 23
6 4
11 19 24 26 29 30
*/
int T;

bool checkAns(const vector<int>& data, int s, int val) {
    int n = data.size();
    bool ans = true;
    int count = 1;
    int start = 0;
    for (int i = 1; i < n && count < s; i++) {
        if (data[i] - data[start] < val) {
            continue;
        } else {
            start = i;
            count++;
        }
    }
    if (count < s) {
        return false;
    } else {
        return true;
    }
}

void solve() {
    int n, s;
    vector<int> data;
    cin >> n;
    cin >> s;
    int e;
    for (int i = 0; i < n; i++) {
        scanf("%d", &e);
        data.push_back(e);
    }

    sort(data.begin(), data.end());

// BRUTE FORTE
//    int ans = 1;
//    for (ans = 1; ans < data.back(); ans++) {
////       cout << "check ans: " << ans << endl;
//        if (checkAns(data, s, ans)) {
//            continue;
//        } else {
//            break;
//        }
//    }

//	ans--;


// BINARY SEARCH
    int beg = 1;
    int end = data[n - 1];
    int ans = (beg + end) / 2;
    while (beg < end - 1) {
        if (checkAns(data, s, ans)) {
            beg = ans;
        } else {
            end = ans;
        }
        ans = (beg + end) / 2;
    }

    if (checkAns(data, s, ans)) {
        ans = beg;
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;

    while (T > 0) {
        solve();
        T--;
    }
    return 0;
}

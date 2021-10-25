#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/*
5
3 2 3
4 0 1
4 4 5
8 10 20
12 0 77
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
    int n, a, b;
    cin >> n;
    cin >> a;
    cin >> b;

    vector<int64_t> data;

    // cal with 1,2,3,4...,n-1, n

    // n = 1
    data.push_back(1);

    // n = 2
    data.push_back(1);

    for (int i = 3; i <= n; i++) {
        int size = data.size();
        int64_t val = 0;
        for (int j = 0; j < size; j++) {
            val += data[j];
            data[j] = val;
        }
        int nums = (size * (size - 1)) / 2;
        if (nums % 2 == 1) {
            for (int j = size - 1; j >= 0; j--) {
                data.push_back(data[j]);
            }
        } else {
            for (int j = size - 2; j >= 0; j--) {
                data.push_back(data[j]);
            }
        }
    }

    for (auto e : data) {
        cout << e << " ";
    }
    cout << endl;

    // cal with 1,2,3,4,...,n-1, n, n
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

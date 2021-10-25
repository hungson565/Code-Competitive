// https://codejam.lge.com/problem/15931

// build: g++ -o 15705 15705.cpp -std=c++11 && 15705

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*

TC:

47

*/



void solve() {
    int missing;
    // cin >> missing;

    // int remain = 52 - missing;

    for (int remain = 0; remain <= 52; remain++) {

    int max = remain / 5;
    if (max > 8) {
        max = 8;
    }

    int min = 0;
    if (remain > 26 && remain <= 36) {
        min = (remain - 25) / 2;
    } else if (remain > 36 && remain <= 43) {
        min = 6;
    } else if (remain > 43 && remain < 48) {
        min = 7;
    } else if (remain >= 48) {
        min = 8;
    } else {
        min = 0;
    }

    cout << "remain = " << remain << ": " << min << " " << max << endl;
    }
}

int main() {
    solve();
}

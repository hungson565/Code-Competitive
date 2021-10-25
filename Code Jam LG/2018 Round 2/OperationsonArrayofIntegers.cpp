// https://codejam.lge.com/problem/15932
// build: g++ -o 15738 15738.cpp -std=c++11 && 15738

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

6 5 6
a
a
r 0 4
a
r 2 5
0 1 2 3 4 5

*/

struct P {
    char type;
    int64_t begin;
    int64_t end;
};

void solve() {
	int64_t N;
    int64_t q;
    int64_t M;
    cin >> N;
    cin >> q;
    cin >> M;

    vector<P> data;

    for (int64_t i = 0; i < q; i++) {
        // operator
        char ope;
        // scanf("%c", &ope);
        cin >> ope;
        if (ope == 'r') {
            // reserve
            int64_t b, e;
            scanf("%d", &b);
            scanf("%d", &e);
            data.push_back({ope, b, e});
        } else {
            // add
            data.push_back({ope});
        }
    }

    for (int64_t i = 0; i < M; i++) {
        int64_t idx;
        // cin >> idx;
        scanf("%d", &idx);
        int64_t origin_idx = idx;
        // find origin_idx
        for (int64_t i = q - 1; i >= 0; i--) {
            if (data[i].type == 'r') {
                if (data[i].begin <= origin_idx && data[i].end >= origin_idx) {
                    origin_idx = (data[i].begin + data[i].end - origin_idx);
                }
            }
        }
        // find value from origin_idx
        int64_t ans = 0;
        for (int64_t i = 0; i < q; i++) {
            if (data[i].type == 'r') {
                if (data[i].begin <= origin_idx && data[i].end >= origin_idx) {
                    origin_idx = (data[i].begin + data[i].end - origin_idx);
                }
            } else {
                ans += origin_idx;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    solve();
}

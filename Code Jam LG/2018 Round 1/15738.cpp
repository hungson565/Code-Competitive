// https://codejam.lge.com/problem/15738

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

5 1 2
1 3 2 4 5
3
-4


*/

void solve() {
	int N;
    int K;
    int M;
    cin >> N;
    cin >> K;
    cin >> M;

    int val;
    vector<int> data;
    for (int i = 0; i < N; i++) {
        scanf("%d", &val);
        // data.push_back(val);
    }

    int e;
    int idx = K - 1;
//    cout << "initial, idx: " << idx << endl;
    for (int i = 0; i < M; i++) {
        scanf("%d", &e);
        // process
        if (e == 0) {
            continue;
        }
        bool left = e > 0;
        e = abs(e);

        if (left) {
            if (idx > e - 1) {
//            	cout << "continue 1" << endl;
                continue;
            }
            idx = e - 1 - idx;
        } else {
            if (N - 1 - e >= idx) {
//            	cout << "continue 2" << endl;
                continue;
            }
            idx = N + N - 1 - e - idx;
        }
//        cout << "after i: " << i << ", idx: " << idx << endl;
    }
    cout << idx + 1 << endl;
}

int main() {
    solve();
}

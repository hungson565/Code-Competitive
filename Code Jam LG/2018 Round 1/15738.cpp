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
    }

    int operand;
    int idx = K;
    for (int i = 0; i < M; i++) {
        scanf("%d", &operand);
        // process
        if (operand == 0) {
            continue;
        }
        bool left = operand > 0;
        operand = abs(operand);

        if (left) {
            if (idx > operand) {
                continue;
            }
            idx = operand + 1 - idx;
        } else {
            if (N + 1 - operand > idx) {
                continue;
            }
            idx = N + N - 3 - operand - idx;
        }
    }
    cout << idx << endl;
}

int main() {
    solve();
}

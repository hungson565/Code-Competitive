// https://codejam.lge.com/problem/17434

// build: g++ -o StreetCleaning StreetCleaning.cpp -std=c++11 && StreetCleaning

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int T;
int N;

/*



TC:

5
4 5
1 1 1 2 3
2 2 3 4 4
4 5
1 1 1 2 3
2 2 3 4 4
4 3
1 1 1
2 3 4
6 5
1 1 1 1 1
2 3 4 5 6
2 1
2
1

*/

void solve() {
    int N;
    int M;
    vector<int> v1;
    vector<int> v2;
    int val1, val2;
    for (int i = 0; i < M; i++) {
        cin >> val1;
        v1.push_back(val1);
    }
    for (int i = 0; i < M; i++) {
        cin >> val2;
        v2.push_back(val2);
    }

    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

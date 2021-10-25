// https://codejam.lge.com/problem/17430

// build: g++ -o Streetlightposts Streetlightposts.cpp -std=c++11 && Streetlightposts

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

2
6
2 3
2 -3
2 1
-2 3
-2 1
-2 -3
6
2 4
2 -3
2 1
-2 3
-2 1
-2 -3

*/

struct P {
    int x;
    int y;
    P(int x1, int y1) : x(x1), y(y1) {}
};

void solve() {
    // input
	cin >> N;
    
    int x;
    int y;

    unordered_set<int> m_x;
    unordered_set<int> m_y;

    for(int i = 0; i < N; ++i) {
        scanf("%d", &x);
        scanf("%d", &y);

        m_x.insert(x);
        m_y.insert(y);
    }

    bool ans = true;

    if (m_x.size() * m_y.size() == N) {
        ans = true;
    } else {
        ans = false;
    }

    if (ans == false) {
        printf("NOT BALANCED\n");
    } else {
        printf("BALANCED\n");
    }
    
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

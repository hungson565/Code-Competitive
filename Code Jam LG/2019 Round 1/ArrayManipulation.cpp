// https://codejam.lge.com/problem/17123
// build: 

// g++ -o ArrayManipulation ArrayManipulation.cpp -std=c++11 && ArrayManipulation

#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

/*
3
3 3
1 2 3
4 5 6
7 8 9
1 1 2 3 3
2 2 3 2 -5
1 1 3 2 1
2 1
10 20
30 40
1 1 2 2 -30
1 3
1000
1 1 1 1 1000
1 1 1 1 -1000
1 1 1 1 1000
*/


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t tc;
    cin >> tc;
    while (tc--) {
        int N;
        int M;
        
        int r1, c1, r2, c2, v;
        cin >> N;
        cin >> M;
        int64_t val;

        vector<vector<int64_t>> data(N + 5, vector<int64_t>(N + 5, 0));

        for (int64_t i = 0; i < N; i++) {
            for (int64_t j = 0; j < N; j++) {
                // scanf("%d", &val);
                cin >> val;
                data[i][j] = val;
            }
        }

        vector<int64_t> r(N + 5, 0);
        vector<int64_t> c(N + 5, 0);

        for (int64_t i = 0; i < N; i++) {
            for (int64_t j = 0; j < N; j++) {
                r[i] += data[i][j];
                c[j] += data[i][j];
            }
        }

        // query

        for (int64_t i = 0; i < M; i++) {
            // scanf("%d%d%d%d%d", &r1, &c1, &r2, &c2, &v);
            cin >> r1;
            cin >> c1;
            cin >> r2;
            cin >> c2;
            cin >> v;

            for (int64_t row = r1 - 1; row <= r2 - 1; row++) {
                r[row] += v * (c2 - c1 + 1);
            }
            for (int64_t column = c1 - 1; column <= c2 - 1; column++) {
                c[column] += v * (r2 - r1 + 1);
            }
        }


        for (int64_t i = 0; i < N; i++) {
            printf("%d", r[i]);
            if (i != N - 1) {
                printf(" ");
            }
        }
        printf("\n");
        
        for (int64_t i = 0; i < N; i++) {
            printf("%d", c[i]);
            if (i != N - 1) {
                printf(" ");
            }
        }
        printf("\n");

    }
    return 0;
}

// build: g++ -o ProblemC ProblemC.cpp -std=c++11 && ProblemC

#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <deque>

// C++ Program to implement the
// above approach
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type,
             less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;

// Input, output
#include <iostream>
string file_name = "ProblemC.in";
ifstream input;

void solve() {
    // code here
    int n, m, d;
    input >> n;
    input >> m;
    input >> d;
    vector<vector<char>> data(n, vector<char>(m, '.'));
    char val;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            input >> val;
            data[i][j] = val;
        }
    }

    //  for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << data[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (data[i][j] != '*') {
                continue;
            }

            // cout << "i: " << i << ", j: " << j << endl;

            if (i == 0 || j == 0 || j == m - 1) {
                continue;
            }
            if (i != n - 1 && (data[i + 1][j + 1] == '*' || data[i + 1][j - 1] == '*')) {
                continue;
            }
            // if (data[])

            int ans = true;
            for (int k = 1; k <= d; k++) {
                int new_x = i - k;
                int new_y = j - k;
                int new_x2 = i - k;
                int new_y2 = j + k;

                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && data[new_x][new_y] == '*') {

                } else {
                    ans = false;
                    break;
                }

                if (new_x2 >= 0 && new_x2 < n && new_y2 >= 0 && new_y2 < m && data[new_x2][new_y2] == '*') {

                } else {
                    ans = false;
                    break;
                }
            }

            if (ans == false) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    set<int> a;

    input.open(file_name);

    input >> t;
    while (t--) {
        solve();
    }

    input.close();
    return 0;
}

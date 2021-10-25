// build: g++ -o ProblemA ProblemA.cpp -std=c++11 && ProblemA

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

// cin, output
#include <iostream>
string file_name = "ProblemA.in";
// ifstream cin;

void solve() {
    // code here
    int n;
    int d;
    cin >> n;
    cin >> d;
    vector<vector<int>> data(n, vector<int>(n, 0));
    int val;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val;
            data[i][j] = val;
        }
    }

    // process d
    d = d % 360;
    if (d < 0) {
        d += 360;
    }

    // cout << "d: " << d << endl;

    for (int round = 0; round < d / 45; round++) {
        // rotate
        vector<vector<int>> copy = data;
        for (int i = 0; i < n; i++) {
            data[i][(n - 1) / 2] = copy[i][i];
        }
        for (int i = 0; i < n; i++) {
            data[i][(n - 1 - i)] = copy[i][(n - 1) / 2];
        }
        for (int i = 0; i < n; i++) {
            data[(n - 1) / 2][(n - 1 - i)] = copy[i][n - 1 -i];
        }
        for (int i = 0; i < n; i++) {
            data[i][i] = copy[(n - 1) / 2][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    set<int> a;

    // cin.open(file_name);

    cin >> t;
    while (t--) {
        solve();
    }

    // cin.close();
    return 0;
}

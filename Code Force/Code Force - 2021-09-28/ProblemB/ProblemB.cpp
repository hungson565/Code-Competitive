// build: g++ -o ProblemB ProblemB.cpp -std=c++11 && ProblemB

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
string file_name = "ProblemB.in";
// ifstream cin;

void solve() {
    // code here
    int n;
    cin >> n;
    vector<int> data(n, 0);
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        data[i] = val;
    }

    int num = 0;
    vector<pair<int, int>> ans;

    for (int i = n - 1; i >= 0; i--) {
        int idx = -1;
        int m = INT_MIN;
        for (int j = 0; j <= i; j++) {
            if (data[j] >= m) {
                idx = j;
                m = max(m, data[j]);
            }
        }

        if (idx == i) {
            continue;
        }
        // cout << idx + 1 << " " << i + 1 << " 1" << endl;
        ans.push_back({idx + 1, i + 1});
        num++;

        for (int j = idx; j <= i - 1; j++) {
            data[j] = data[j + 1];
        }
        data[i] = m;
    }
    cout << num << endl;
    for (auto e : ans) {
        cout << e.first << " " << e.second << " 1" << endl;
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

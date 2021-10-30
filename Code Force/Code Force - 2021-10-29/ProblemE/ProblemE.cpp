
// build: g++ -o ProblemE ProblemE.cpp -std=c++11 && ProblemE

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
typedef tree<pair<int64_t, int64_t>, null_type,
             less_equal<pair<int64_t, int64_t>>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;

#include <iostream>
string file_name = "ProblemE.in";

/*
6

14 1
1 2
2 3
2 4
4 5
4 6
2 7
7 8
8 9
8 10
3 11
3 12
1 13
13 14

2 200000
1 2

3 2
1 2
2 3

5 1
5 1
3 2
2 1
5 4

6 2
5 1
2 5
5 6
4 2
3 4

7 1
4 3
5 1
1 3
6 1
1 7
2 1
*/

void solve() {
    int64_t n, k;
    cin >> n >> k;
    vector<vector<int64_t>> adj(n + 10);

    int64_t x, y;
    // cout << "n: " << n << endl;
    for (int64_t i = 0; i < n - 1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // bfs
    vector<int64_t> rank(n + 10, 0);
    queue<int64_t> q;
    for (int64_t i = 1; i <= n; i++) {
        if (adj[i].size() <= 1) {
            q.push(i);
            rank[i] = 1;
        }
    }
    // cout << "q.size(): " << q.size() << endl;

    while (!q.empty()) {
        auto e = q.front();
        q.pop();
        for (auto f : adj[e]) {
            if (rank[f] == 0) {
                rank[f] = rank[e] + 1;
                q.push(f);
                // cout << "push: " << f << endl;
            }
        }
    }

    int64_t ans = 0;
    for (int64_t i = 1; i <= n; i++) {
        if (rank[i] > k) {
            ans++;
        }
    }

    if (n <= 1) {
        cout << "0" << "\n";
        return;
    }

    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int64_t t;

    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

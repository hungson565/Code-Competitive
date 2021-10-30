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

/*
4
8 3
6 6
7 1
1 1
*/


void solve() {
    int64_t n, k;
    cin >> n >> k;
    int64_t t;
    // find t that 2^t <= k
    // t = (int64_t) log2(k);

    for (t = 0; t < 100; t++) {
        if (pow(2, t + 1) <= n && pow(2, t) <= k) {
            // t++;
            // cout << "t: " << t << endl;
        } else {
            break;
        }
    }
    t--;

    int64_t h;
    h = (n - (int64_t) pow(2, t + 1)) / k;
    int64_t ans = (t + 1) + h;
    if ((n - (int64_t) pow(2, t + 1)) % k != 0) {
        ans++;
    }
    // cout << "t: " << t << ", h: " << h << endl;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    // cin.open(file_name);

    cin >> t;
    while (t--) {
        solve();
    }

    // cin.close();
    return 0;
}

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
3
3 4
2 12
105 564
*/

int64_t myPow(int64_t n, int64_t count) {
    if (count == 0) {
        return 1;
    }
    if (count == 1) {
        return n;
    }
    if (count % 2 == 0) {
        return ((myPow(n, count / 2) % 1000000007) * (myPow(n, count / 2) % 1000000007)) % 1000000007;
    }
    return ((((myPow(n, (count - 1) / 2) % 1000000007) * (myPow(n, (count - 1) / 2) % 1000000007)) % 1000000007) * n) % 1000000007;
    // return 1;
}

void solve() {
    // code here
    int64_t n, k;
    int64_t ans = 0;
    cin >> n;
    cin >> k;
    int64_t count = 0;
    while (k > 0) {
        if (k & 1) {
            ans = (ans + myPow(n, count)) % 1000000007;
            // cout << "k: " << k << ", count: " << count << endl;
        }
        count++;
        k = k >> 1;
    }
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

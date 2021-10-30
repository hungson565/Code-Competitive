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
/*
4
3 13
0 1 2
2 777
0 4
3 255
0 1 3
10 1000000000
0 1 2 3 4 5 6 7 8 9
*/

void solve() {
    
    int64_t n, k;
    cin >> n >> k;
    int64_t ans = 0;
    vector<int64_t> coff;
    int64_t val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        coff.push_back(pow(10, val));
    }

    k++;

    sort(coff.begin(), coff.end());
    int64_t h = 0;
    int i;
    for (i = 0; i < coff.size() - 1 && k > h; i++) {
        int64_t x;
        x = coff[i + 1] / coff[i] - 1;
        x = min(x, k - h);
        // k -= x;
        h += x;
        ans += coff[i] * x;
        // cout << "new ans: " << ans << endl;
    }

    ans += coff[i] * (k - h);
    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    // set<int> a;

    // input.open(file_name);

    cin >> t;
    while (t--) {
        solve();
    }

    // input.close();
    return 0;
}

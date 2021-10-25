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
    int64_t n;
    cin >> n;
    int64_t a = 1 - n;
    int64_t b = n;
    cout << a << " " << b << endl;
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

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
/*
5
0 0 0
10 75 15
13 13 17
1000 0 0
0 1000000000 0
*/

void solve() {
    // code here
    int a, b, c;
    cin >> a >> b >> c;
    int ans1, ans2, ans3;
    ans1 = max(b, c) + 1;
    if (ans1 <= a) {
        ans1 = 0;
    } else {
        ans1 = ans1 - a;
    }

    ans2 = max(a, c) + 1;
    if (ans2 <= b) {
        ans2 = 0;
    }else {
        ans2 = ans2 - b;
    }

    ans3 = max(a, b) + 1;
    if (ans3 <= c) {
        ans3 = 0;
    }else {
        ans3 = ans3 - c;
    }

    cout << ans1 << " " << ans2 << " " << ans3 << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    // set<int> a;

    // cin.open(file_name);

    cin >> t;
    while (t--) {
        solve();
    }

    // cin.close();
    return 0;
}

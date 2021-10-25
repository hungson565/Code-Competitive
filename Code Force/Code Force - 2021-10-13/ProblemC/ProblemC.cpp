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
3
6
1 5 3 1 1 5
8
-1 0 1 -1 0 1 -1 0
4
100 -1000 -1000 -1000
*/

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    if (a == b) {
        return a;
    }
    if (a > b) {
        return gcd(a % b, b);
    }
    return gcd(b % a, a);
    // return 2;
}

void solve() {
    
    int n;
    cin >> n;
    vector<int> x;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        x.push_back(val);
    }

    vector<int> y;
    for (int i = 0; i < n - 1; i++) {
        // if ((x[i + 1] - x[i]) != 0)
            y.push_back(abs(x[i + 1] - x[i]));
    }

    bool same = true;
    for (int i = 0; i < y.size() - 1; i++) {
        if (y[i] != y[i + 1]) {
            same = false;
        }
    }

    if (same) {
        cout << "-1" << endl;
        return;
    }

    // for (auto e : y) {
    //     cout << e << " ";
    // }
    // cout << endl;

    // // find GCD
    int GCD = gcd(y[0], y[1]);
    for (int i = 0; i < y.size(); i++) {
        GCD = gcd(GCD, y[i]);
    }

    cout << GCD << endl;

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

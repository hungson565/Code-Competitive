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
5
100
71345
3259
50555
2050047
*/


void solve() {
    // code here
    string s;
    cin >> s;
    int n = s.size();

    int ans1 = n;
    int ans2 = n;

    // case 1, end by 0
    int i = n - 1;
    while (i >= 0 && s[i] != '0') {
        i--;
    }
    i--;
    // cout << "i1: " << i << endl;
    if (i >= 0) {
        while (i >= 0 && (s[i] != '5' && s[i] != '0')) {
            i--;
        }
        // cout << "i2: " << i << endl;
        if (i > 0 || (i == 0 && (s[i] == '5' || s[i] == '0'))) {
            ans1 = (n - i - 2);
        }
    }

    // case 2, end by 5
    i = n - 1;
    while (i >= 0 && s[i] != '5') {
        i--;
    }
    i--;
    // cout << "i11: " << i << endl;
    if (i >= 0) {
        while (i >= 0 && (s[i] != '2' && s[i] != '7')) {
            i--;
        }
        // cout << "i22: " << i << endl;
        if (i > 0 || (i == 0 && (s[i] == '2' || s[i] == '7'))) {
            ans2 = (n - i - 2);
        }
    }
    // cout << "ans1: " << ans1 << endl;
    // cout << "ans2: " << ans2 << endl;

    int ans = min(ans1, ans2);
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

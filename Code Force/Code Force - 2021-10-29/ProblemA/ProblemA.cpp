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
4
b
aabbbabaa
abbb
abbaab
*/

void solve() {
    // code here
    string s;
    cin >> s;
    int ab = 0;
    int ba = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'a') {
            if (s[i + 1] == 'b') {
                ab++;
            }
        } else {
            if (s[i + 1] == 'a') {
                ba++;
            }
        }
    }

    string ans = s;
    if (ab == ba) {
        //ans = s;
    } else if (ab > ba) {
        int diff = ab - ba;
        int count = 0;
        for (int i = 0; i < s.size() - 1 && count < diff; i++) {
            if (s[i] == 'a') {
                ans[i] = 'b';
                count++;
            }
        }
    } else {
        int diff = ba - ab;
        int count = 0;
        for (int i = 0; i < s.size() - 1 && count < diff; i++) {
            if (s[i] == 'b') {
                ans[i] = 'a';
                count++;
            }
        }
    }
    cout << ans << endl;

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

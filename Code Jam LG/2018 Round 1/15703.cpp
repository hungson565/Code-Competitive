#include <iostream>

// C++ Program to implement the
// above approach
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
// Make __builtin_popcount faster: https://codeforces.com/blog/entry/13134?#comment-736517
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

// Ordered set
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type,
             less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;

// MACRO
// #define int long long
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)

#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int)(x).size())
#define ALL(a) (a).begin(), (a).end()
#define TWO(x) (1LL<<(x))
inline int gcd(int a, int b) {int r; while (b) {r = a % b; a = b; b = r;} return a;}

// For printing pair, container, etc.
// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
template<class U, class V> ostream& operator << (ostream& out, const pair<U, V>& p) {
    return out << '(' << p.first << ", " << p.second << ')';
}
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator << (ostream& out, const Con& con) {
    out << '{';
    for (auto beg = con.begin(), it = beg; it != con.end(); it++) {
        out << (it == beg ? "" : ", ") << *it;
    }
    return out << '}';
}


// ----------------------------------------------
// ideal

// Input, output
#include <iostream>
#include <string>

const int MOD = 987654323;

bool operator < ( pair<int, int> p1, pair<int, int> p2 ) {
    if (p1.second != p2.second) {
        return p1.second < p2.second;
      }
      return p1.first > p2.first;
}

void solve();

int32_t  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    solve();
    return 0;
}

void solve() {
	int N;
    cin >> N;
    set<pair<int, int>> s;
    int val;
    for (int i = 0; i < N; i++) {
        cin >> val;
        s.insert({val, i});
    }

    int ans = 0;
    int find = 0;
    while (!s.empty()) {
        auto it = s.lower_bound({find, 0});
        if  (it != s.end()) {
            s.erase(it);
            find++;
        } else {
            ans++;
            find = 0;
        }
    }
    ans++;

    cout << ans << endl;
}

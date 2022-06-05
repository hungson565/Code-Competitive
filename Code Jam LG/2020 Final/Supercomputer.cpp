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
#define int long long
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)6

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

const int MOD = 1e9 + 7;

// bool operator < ( pair<int, int> p1, pair<int, int> p2 ) {
//     if (p1.second != p2.second) {
//         return p1.second < p2.second;
//       }
//       return p1.first > p2.first;
// }

class ST {
  int n;
  vector<int> tree;
public:
  ST(const vector<int>& data) {
    int N = data.size();
    n = N;
    tree.resize(2 * n);
    for (int i = 0; i < n; i++) {
      tree[i + n] = data[i];
    }
    build();
  }

  void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) tree[i] = tree[i<<1] + tree[i<<1|1];
  }

  void modify(int p, int value) {  // set value at position p
    for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = tree[p] + tree[p^1];
  }

  int query(int l, int r) {  // sum on interval [l, r]
    r++;
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += tree[l++];
      if (r&1) res += tree[--r];
    }
    return res;
  }  
};

struct Point {
    int x;
    int y;
    Point(int xx, int yy) : x(xx), y(yy) {}
};

int pow(int a, int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return a;
    }
    if (n % 2 == 0) {
        return (pow(a, n/2) * pow(a, n/2)) % MOD;
    }
    return (((pow(a, n/2) * pow(a, n/2)) % MOD) * a) % MOD;
}


#define MAX 1e6
#define INF 1e9 + 5

void solve()
{
    int n; cin >> n;
    vector<int> H(n);
    vector<int> D(n);
    for (auto& h : H) cin >> h;
    for (auto& d : D) cin >> d;

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
        p.push_back({D[i], H[i]});
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        D[i] = p[i].first;
        H[i] = p[i].second;
    }

    vector<int> pre(n);
    pre[0] = H[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + H[i];
    }
    vector<int> C(n);
    
    for (int i = 0; i < n; i++) {
        C[i] = pre[i] - D[i];
        if (C[i] < 0) C[i] = 0;
    }

    vector<int> max_left(n, 0);
    vector<int> max_right(n, 0);

    for (int i = 1; i < n; i++) {
        max_left[i] = max(max_left[i - 1], C[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--) {
        max_right[i] = max(max_right[i + 1], C[i + 1]);
    }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        int v = max_left[i];
        v = max(v, C[i] - (H[i] - 1));
        v = max(v, max_right[i] - (H[i] - 1));
        if (v < 0) {
            v = 0;
        }

        ans = min(ans, v);
    }

    cout << ans << endl;

}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T > 0)
    {
        solve();
        T--;
    }

    return 0;
}
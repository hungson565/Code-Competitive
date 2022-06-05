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

// ----------------------------------------------
// ideal




// ----------------------------------------------

/*

4
4
5 1 3 2
4
10 8 5 7
7
1 2 3 100 10 20 30
7
1000 1000 1000 1000 1000 1000 1000

*/

// Input, output
#include <iostream>
string file_name = "ProblemA.in";
ifstream input;
#include <string>

#define M 1000
// #define int int64_t


/*

6
2 1
1 -2
1 2 3
2 1
1 -2
2 1 3
3 2
4 -1 -2
1 2 1
2 3 1
3 6
10 10 10
1 2 2
2 1 3
1 3 4
3 1 5
2 3 6
3 2 7
2 1
1 -5
1 2 1
3 2
1 1 -2
1 3 1
2 3 1

*/

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v;
  int val;
  for (int i = 0; i < n; i++) {
    cin >> val;
    v.push_back(val);
  }

 vector<map<int, int>> deg(n + 10);

  int x, y, z;
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    deg[x - 1][y - 1] = z;
  }

  vector<int> dp(n + 10, 0);

  // fisrt, choose
  vector<bool> best(n + 10, true);

  int sum = 0;
  for (auto e : v) {
    sum += e;
  }

  // if (sum < 0) {
  //   cout << "anszz: 0" << endl;
  //   return;
  // }

  // remove

  int T = n;
  while (T > 0) {
    int   = INT_MAX;
    int pick_to_remove = -1;
    for (int i = 0; i < n; i++) {
      if (best[i] == false) {
        continue;
      }

      int val = v[i];
      for (int j = 0; j < n; j++) {
        if (j == i) {
          continue;
        }
        if (best[j]) {
          val += deg[j][i];
        } else {
          val -= deg[i][j];
        }
      }

      if (val < 0 && val < sub) {
        sub = val;
        pick_to_remove = i;
      }

    }

    if (pick_to_remove == -1) {
      break;
    }
    best[pick_to_remove] = false;
    sum -= sub;
    T--;

  }

  if (sum < 0) {
    sum = 0;
  }

  cout << sum << endl;

}
/*
3 2
4 -1 -2
1 2 1
2 3 1

3 6
10 10 10
1 2 2
2 1 3
1 3 4
3 1 5
2 3 6
3 2 7
*/


int32_t  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    cin >> t;
    for (int i = 0; i < t; i++) {
      solve();
    }

    return 0;
}

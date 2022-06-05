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


// ----------------------------------------------
// ideal


// Input, output
#include <iostream>
#include <string>

const int MOD = 987654323;

// vector<int> giai_thua(1000006);

void solve() {
  // input
  int n;
  cin >> n;
  vector<int> data(n + 1, 0);
  int val;
  int m = 0;
  for (int i = 1; i <= n; i++) {
    cin >> val;
     m += val;
    // data.push_back(val);
    data[i] = val;
  }

  int M = m;

  // cout << "data" << endl;
  // for (auto e : data) {
  //   cout << e << " ";
  // }
  // cout << endl;

  vector<int> ans(m + 1, 0);

  int mmax = 0;
  for (auto e : data) {
    mmax = max(mmax, e);
  }
  if (m % 2 == 0) {
    if (mmax >= (m / 2) + 1) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  } else {
    if (mmax > (m / 2) + 1) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }

  int last = -1;

  for (int i = 1; i <= M; i++) {

    // find ans[i]

    bool lon = false;
    for (int pick = 1; pick <= n; pick++) {
      if (pick == last) {
        continue;
      }

      if ((m - 1) % 2 == 0) {
        if (data[pick] >= ((m - 1) / 2) + 1) {
          ans[i] = pick;
          last = pick;
          data[pick]--;
          m--;
          lon = true;
          // continue;
          break;
        }
      } else {
        if (data[pick] > ((m - 1) / 2) + 1) {
          ans[i] = pick;
          last = pick;
          data[pick]--;
          m--;
          lon = true;
          // continue;
          break;
        }
      }

      if (data[pick] >= (m / 2) + 1) {
        ans[i] = pick;
        last = pick;
        data[pick]--;
        m--;
        lon = true;
        // continue;
        break;
      }

    }

    if (lon == false) {
      for (int pick = 1; pick <= n; pick++) {
        if (pick == last) {
          continue;
        }
        if (data[pick] <= 0) {
          continue;
        }
        ans[i] = pick;
        last = pick;
        m--;
        data[pick]--;
        // lon = true;
        // continue;
        break;
      }
    }

    // cout << "i: " << i << ", pick: " << last << ", m: " << m << endl;

  }

  int s = 0;
  for (int i = 1; i <= M; i++) {
      s = (s + i * ans[i]) % MOD;
  }
  // cout << endl;
  cout << s << endl;


}

int32_t  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    // giai_thua[0] = 1;
    // for (int i = 1; i < 1000006; i++) {
    //   giai_thua[i] = (i * giai_thua[i - 1]) % MOD;
    // }
    cin >> t;
    for (int i = 0; i < t; i++) {
      solve();
    }

    return 0;
}

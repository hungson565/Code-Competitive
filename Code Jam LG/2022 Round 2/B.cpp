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

const int MOD = 1e9 + 7;

vector<int> giai_thua(1000006);

void solve() {
  // input
  int n, m;
  cin >> n >> m;
  vector<int> data;
  int val;
  for (int i = 0; i < n; i++) {
    cin >> val;
    data.push_back(val);
  }

  vector<int> diff(n + 5, 0);

  int beg, end;
  for (int i = 0; i < m; i++) {
    cin >> beg >> end;
    beg--;
    end--;
    // update range beg->end
    diff[beg]++;
    if (end < n - 1) {
      diff[end + 1]--;
    }
  }

  vector<int> id(n, 0);
  id[0] = diff[0];
  for (int i = 1; i < n; i++) {
    id[i] = id[i - 1] + diff[i];
  }

  // cout << "diff" << endl;
  // for (auto e : diff) {
  //   cout << e << " ";
  // }
  // cout << endl;
  // cout << "id" << endl;
  // for (auto e : id) {
  //   cout << e << " ";
  // }
  // cout << endl;

  sort(data.begin(), data.end(), [](int a, int b) {
    return a > b;
  });

  sort(id.begin(), id.end(), [](int a, int b) {
    return a > b;
  });

  int sum = 0;
  int count = 1;
  for (int i = 0; i< n; i++) {
    sum = (sum + data[i] * id[i]);
    // count = (count * giai_thua[id[i]]) % MOD;
    // cout << "id[i]: " << id[i] << ", giai_thua[id[i]]): " << giai_thua[id[i]] << endl;
  }

  unordered_map<int, int> mm;
  for (auto e : id) {
    mm[e]++;
  }

  for (auto e : mm) {
    count = (count * giai_thua[e.second]) % MOD;
  }

  cout << sum << " " << count << endl;


}

int32_t  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    giai_thua[0] = 1;
    for (int i = 1; i < 1000006; i++) {
      giai_thua[i] = (i * giai_thua[i - 1]) % MOD;
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
      solve();
    }

    return 0;
}

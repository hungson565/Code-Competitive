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
#define int int64_t
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


void cal(int node, const vector<int>& val, const vector<vector<int>>& deg, vector<unordered_map<int, pair<int, int>>>& dp) {

  if (deg[node].size() == 0) {
    dp[node][node] = {val[node], val[node]};
  }

  if (dp[node].size() != 0) {
    return;
  }

  int s = 0;
  for (auto sub_node : deg[node]) {
    cal(sub_node, val, deg, dp);
    s += dp[sub_node][sub_node].first;
  }

  for (auto sub_node : deg[node]) {
    int v = s;

    int diff = 0;
    if (dp[sub_node][sub_node].second <= val[node])
      diff = dp[sub_node][sub_node].second - val[node];
    v -= diff;

    // v -= dp[sub_node][sub_node].first;
    // int vv = 0;
    // for (auto sub_sub : deg[sub_node]) {
    //   cal(sub_sub, val, deg, dp);
    //   int V = dp[sub_node][sub_sub].first;
    //   if (dp[sub_node][sub_sub].second < val[node]) {
    //     V += val[node] - dp[sub_node][sub_sub].second;
    //   }
    //   // vv = max(vv, V);
    //   vv = max(vv, V);
    // }
    // v += vv;


    // ans = max(ans, v);
    // cout << "v: " << v << ", diff: " << diff << ", val[node]: " << val[node] << ", dp[sub_node][sub_node].second: " << dp[sub_node][sub_node].second << endl;
    dp[node][sub_node] = {v, max(val[node], dp[sub_node][sub_node].second)};
    // dp[node][node].first = max(dp[node][node].first, v);
    if (dp[node][node].first < v) {
      dp[node][node].first = v;
      dp[node][node].second = max(dp[sub_node][sub_node].second, val[node]);
    }
    // cout << "node: " << node << ", sub_node: " << sub_node << ", v: " << v << ", s: " << s << endl;
  }

}


void solve(int i) {
  int N;
  cin >> N;
  int in;
  vector<int> val = {0};
  for (int i = 1; i <= N; i++) {
    cin >> in;
    val.push_back(in);
  }

  vector<vector<int>> deg(N + 1, vector<int>());
  for (int i = 1; i <= N; i++) {
    cin >> in;
    deg[in].push_back(i);
  }

  vector<unordered_map<int, pair<int, int>>> dp(N + 1);

  cal(0, val, deg, dp);

  int ans = 0;

  // for (auto e : dp[0]) {
  //   ans = max(ans, e.first);
  // }

  ans = dp[0][0].first;

  cout << "Case #" << i << ": " << ans << endl;

  for (int i = 0; i <= N; i++) {
    cout << "i: " << i << endl;
    for (auto e : dp[i]) {
      cout << e.first << ": " << e.second << endl;
    }
  }


}

// 2 1 20 22
// 2 3 37 55
/*
3
10 15 25
4
24 36 20 30
*/

int32_t  main() {
    // sieve();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
      solve(i + 1);
    }

    return 0;
}

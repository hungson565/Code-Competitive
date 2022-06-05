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

#define M 1000
// #define int int64_t


/*

6
3
10 15 25
4
24 36 20 30
6
10 20 30 30 20 10
4
12 18 24 36
8
10 10 20 20 20 30 30 30
4
1 1 1 2

*/


#define MAXN   1000009
 
// stores smallest prime factor for every number
// int spf[MAXN];
vector<int> spf(MAXN);

// vector<vector<int>> dic(MAXN);


/*
6
3
10 15 25
4
24 36 20 30
*/

void solve(int i) {
  int N;
  cin >> N;
  vector<int> arr;
  int val;
  for (int i = 0; i < N; i++) {
    cin >> val;
    arr.push_back(val);
  }

  cout << "Case #" << i << ": ";

  sort(arr.begin(), arr.end());

  int ans = 0;
  for (auto e : arr) {
    if (e >= ans + 1) {
      ans++;
    }
  }
  
  cout << ans << endl;
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

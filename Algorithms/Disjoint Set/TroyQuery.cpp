// https://codeforces.com/gym/100571/problem/F

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

#define M 300000
#define int int64_t
 
class DJ {
public:
    DJ(int N) : N(N) {
        init();
    }    
    int parent[M], rank[M];
    int count[M];

    void init() {
        for (int i=0; i<N; i++) {
            parent[i] = i;
            rank[i] = 0;
            count[i] = 1;
        }
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (rank[u] == rank[v]) rank[u]++;
        if (rank[u] < rank[v]) {
            parent[u] = v;
            count[v] += count[u];
        }
        else {
            parent[v] = u;
            count[u] += count[v];
        }
    }
    
    int getCount(int i) {
        return count[i];
    }
private:
    int N;
};

void solve() {
  int n;
  cin >> n;
  int r = 0;
  int c = 2 * n;
  unordered_map<int, int> mr;
  unordered_map<int, int> mc;

  DJ dj(n * 4 + 10);

  bool found = false;

  for (int i = 0; i < n; i++) {
    int x, y, a, b;
    // cin >> x >> y >> a >> b;

    scanf("%lld", &x);
    scanf("%lld", &y);
    scanf("%lld", &a);
    scanf("%lld", &b);

    if (found == true) {
    //   cout << "No" << endl;
      printf("No\n");
      continue;
    }

    int rr;
    int cc;

    if (mr.count(x)) {
      rr = mr[x];
    } else {
      rr = r;
      mr[x] = rr;
      r++;
    }

    if (mc.count(y)) {
      cc = mc[y];
    } else {
      cc = c;
      mc[y] = cc;
      c++;
    }

    if (a == b) {
      dj.join(rr, cc);
      dj.join(rr + n, cc + n);
    } else {
      dj.join(rr, cc + n);
      dj.join(cc, rr + n);
    }

    if (dj.find(rr) == dj.find(rr + n) || dj.find(cc) == dj.find(cc + n)) {
      found = true;
    //   cout << "No" << endl;
      printf("No\n");
    } else {
    //   cout << "Yes" << endl;
      printf("Yes\n");
    }

  }

}

int32_t  main() {
    solve();

    return 0;
}

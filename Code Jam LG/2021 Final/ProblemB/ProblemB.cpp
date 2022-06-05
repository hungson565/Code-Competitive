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

// bool operator < ( const string& p1, const string& p2 ) {
    
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


// #define MAX 1e6
#define INF 1e9 + 5

bool isPrime[100005];
vector<int> primes;
vector<int> check(100005, false);

string reversE(const string& s) {
    string ans = s;
    reverse(ans.begin(), ans.end());
    return ans;
}

int n;

int giai_thua[30];

void solve()
{
    memset(giai_thua, 1, sizeof(giai_thua));
    giai_thua[0] = 1;
    giai_thua[1] = 1;
    for (int i = 2; i < 30; i++) {
      giai_thua[i] = (i * giai_thua[i - 1]) % MOD;
    }

    int n, m, x, C, D;
    cin >> n >> m >> x >> C >> D;
    vector<int> a(n);
    vector<int> b(m);

    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;

    vector<vector<int>> A(n + 1);
    vector<vector<int>> B(m + 1);

    for (int mask = 0; mask < (1 << n); mask++) {
      int cnt = 0;
      int sum = 0;
      for (int bit = 0; bit < n; bit++) {
        if (mask & (1 << bit)) {
          sum += a[bit];
          cnt++;
        }
      }
      A[cnt].push_back(sum);
    }
    for (auto& v : A) {
      sort(v.begin(), v.end());
    }

    for (int mask = 0; mask < (1 << m); mask++) {
      int cnt = 0;
      int sum = 0;
      for (int bit = 0; bit < m; bit++) {
        if (mask & (1 << bit)) {
          sum += b[bit];
          cnt++;
        }
      }
      B[cnt].push_back(sum);
    }
    for (auto& v : B) {
      sort(v.begin(), v.end());
    }

    int ans = 0;

    // 1. choose num = 1 from A
    // num = 1, A[1][i]
    for (int i = 0; i < A[1].size(); i++) {

      // no choose
      if (A[1][i] >= C && A[1][i] <= D) {
        ans++;
      }

      // choose from B[1][i]
      int v1 = 0;
      int l = (C - A[1][i] - x);
      int r = (D - A[1][i] - x);
      int low = lower_bound(B[1].begin(), B[1].end(), l) - B[1].begin();
      int up = upper_bound(B[1].begin(), B[1].end(), r) - B[1].begin();
      v1 = (up - low);
      v1 = (1 * giai_thua[1] * v1 * 2) % MOD;
      ans = (ans + v1) % MOD;

      if (m < 2) {
        continue;
      }

      // choose from B[2][i]
      int v2 = 0;
      l = (C - A[1][i] - 2 * x);
      r = (D - A[1][i] - 2 * x);
      low = lower_bound(B[2].begin(), B[2].end(), l) - B[2].begin();
      up = upper_bound(B[2].begin(), B[2].end(), r) - B[2].begin();
      v2 = (up - low);
      v2 = (1 * giai_thua[2] * v2) % MOD;
      ans = (ans + v2) % MOD;
    }

    // 2. num >= 1
    for (int num = 2; num <= n; num++) {
      for (int i = 0; i < A[num].size(); i++) {
        if (m < num - 1) {
          continue;
        }
        // choose from B[num - 1][i]
        int v2 = 0;
        int l = (C - A[num][i] - (2 * num - 2) * x);
        int r = (D - A[num][i] - (2 * num - 2) * x);
        int low = lower_bound(B[num - 1].begin(), B[num - 1].end(), l) - B[num - 1].begin();
        int up = upper_bound(B[num - 1].begin(), B[num - 1].end(), r) - B[num - 1].begin();
        v2 = (up - low);
        int gt = giai_thua[num] % MOD;
        int gt1 = giai_thua[num - 1] % MOD;
        v2 = (gt * v2) % MOD ;
        v2 = (gt1 * v2) % MOD ;
        ans = (ans + v2) % MOD;

        if (m < num) {
          continue;
        }
        // 2. choose from B[num][i]
        int v1 = 0;
        l = (C - A[num][i] - (2 * num - 1) * x);
        r = (D - A[num][i] - (2 * num - 1) * x);
        low = lower_bound(B[num].begin(), B[num].end(), l) - B[num].begin();
        up = upper_bound(B[num].begin(), B[num].end(), r) - B[num].begin();
        v1 = (up - low);
        gt = giai_thua[num] % MOD;
        // v1 = gt* gt * v1 * 2;
        v1 = (gt * v1) % MOD ;
        v1 = (gt * v1) % MOD ;
        v1 = (2 * v1) % MOD ;
        
        ans = (ans + v1) % MOD;

        if (m < num + 1) {
          continue;
        }
        // choose from B[num + 1][i]
        int v3 = 0;
        l = (C - A[num][i] - (2 * num ) * x);
        r = (D - A[num][i] - (2 * num ) * x);
        low = lower_bound(B[num + 1].begin(), B[num + 1].end(), l) - B[num + 1].begin();
        up = upper_bound(B[num + 1].begin(), B[num + 1].end(), r) - B[num + 1].begin();
        v3 = (up - low);
        gt = giai_thua[num] % MOD;
        gt1 = giai_thua[num + 1] % MOD;
        // v3 = gt * gt1 * v3;
        v3 = (gt * v3) % MOD ;
        v3 = (gt1 * v3) % MOD ;
        ans = (ans + v3) % MOD;

      }
    }

    // 4. pick from only B
    for (auto e : B[1]) {
      if (e >= C && e <= D) {
        ans = (ans + 1) % MOD;
      }
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
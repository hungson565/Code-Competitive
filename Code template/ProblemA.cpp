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
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)6
 
#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
 
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int)(x).size())
#define ALL(a) (a).begin(), (a).end()
#define TWO(x) (1LL<<(x))
inline int gcd(int a, int b) {int r; while (b) {r = a % b; a = b; b = r;} return a;}
 
#define pii pair<int, int>
#define F first
#define S second
 
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
 
#define LOCAL
//Warsaw template
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (_VA_ARGS_) << "] "
 
struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
 
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
    for (int i = n - 1; i > 0; --i) tree[i] = max(tree[i<<1], tree[i<<1|1]);
  }
 
  void modify(int p, int value) {  // set value at position p
    for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = max(tree[p], tree[p^1]);
  }
 
  int query(int l, int r) {  // sum on interval [l, r]
    r++;
    int res = INT_MIN;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = max(res, tree[l++]);
      if (r&1) res = max(res, tree[--r]);
    }
    return res;
  }  
};
 
#define INF 1e9 + 5
#define MOD 1e9 + 7
 
// Input, output
#include <iostream>
 
bool isPrime[100005];
 
void sieve(int N) {
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             // Mark all the multiples of i as composite numbers
             for(int j = i * i; j <= N; j += i)
                 isPrime[j] = false;
        }
    }
}
 
// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
 
void TC() {
    int n, m;
    cin >> n >> m;
 
    // int a[n + 1][m + 1];
 
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    if ((n + m - 1) % 2 == 1) {
      cout << "NO" << endl;
      return;
    } 
 
    // int dp[n + 10][m + 10];
    // memset(dp, 0, sizeof(dp));
 
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            // cout << "min(dp[i - 1][j], dp[i][j - 1]) : " << dp[i - 1][j]  << endl;
            // cout << dp[i][j] << ", ";
        }
        // cout << endl;
    }
 
    // int dp2[n + 1][m + 1];
    // memset(dp2, 0, sizeof(dp2));
 
    vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]) + a[i][j];
        }
    }
    // cout << dp << endl;
    // cout << a[1][2] << endl;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << dp[i][j] << ", ";
    //     }
    //     cout << endl;
    // }
 
    if (dp[n][m] <= 0 && dp2[n][m] >= 0) {
        cout << "YES" << endl;
    } else
        cout << "NO" << endl;
 
}

/////////////////////////////////////////////////////////////////

int32_t main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	// cin >> t;
	// while(t--)
		TC();
	
}
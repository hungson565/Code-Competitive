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
#define vii vector<int>
#define pb push_back
 
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

class DJ {
public:
    #define M 40000
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
      int parent = find(i);
      return count[parent];
    }
private:
    int N;
};

void TC() {
	int n, b, r;
  cin >> n >> b  >> r;
  vector<int> v(n);
  for (auto& e : v) cin >> e;

  int ans = 0;
  int window = 0;
  unordered_map<int, pair<int, int>> m;


  // find T, cnt
  int T, cnt;

  int start_second_T = -1;

  for (int i = 0; i < n * r; i++) {

    window += v[i % n];
    if (i < n * r - 1 && window + v[(i + 1) % n] > b) {
      ans++;
      // cout << "window: " << window << endl;
      if (m.count(i % n)) {
        T = (i - m[i % n].first) / n;
        cnt = ans - m[i % n].second;
        // cout << "i: " << i << ", i last: " << m[i % n].first << endl;
        start_second_T = i + 1;
        break;
      }
      m[i % n] = {i, ans};
      window = 0;
    }

  }

  if (start_second_T == -1) {
    if (window != 0) ans++;
    cout << ans << endl;
    return;
  }

  // cout << "T: " << T << ", cnt: " << cnt << ", start_second_T: " << start_second_T << ", ans: " << ans << endl;

  int no_cycle_from_second_to_last;
  no_cycle_from_second_to_last = (n * r - 1 - start_second_T + 1) / (T * n);
  // cout << "no_cycle_from_second_to_last: " << no_cycle_from_second_to_last << endl;

  ans += no_cycle_from_second_to_last * cnt;

  int start_remain = start_second_T + no_cycle_from_second_to_last * T * n;

  // cout << "start_remain: " << start_remain << ", ans: " << ans << endl;

  window = 0;
  for (int i = start_remain; i < n * r; i++) {

    window += v[i % n];
    if (i < n * r - 1 && window + v[(i + 1) % n] > b) {
      ans++;
      // cout << "window: " << window << endl;
      // if (m.count(i % n)) {
      //   T = (i - m[i % n].first) / n;
      //   cnt = ans - m[i % n].second;
      //   cout << "i: " << i << ", i last: " << m[i % n].first << endl;
      //   start_second_T = i + 1;
      //   break;
      // }
      // m[i % n] = {i, ans};
      window = 0;
    }

  }

  if (window != 0) ans++;

  cout<< ans << endl;


}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
		TC();
	
}

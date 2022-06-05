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

struct MaxFlow {
    vector< vector< int> > adj;
    vector< int> par;

    unordered_map<pair<int, int>, int, hash_pair> cap;
    unordered_map<pair<int, int>, int, hash_pair> flow;

    int n;
    MaxFlow(int _n) {
        n = _n;
        adj.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            adj[i].resize(3);
        }
        par.resize(n + 1);
    }
    void addEdge(int u, int v, int c) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[{u, v}] += c;
    }
    int bfs(int source, int sink) {
        queue<pii> q;
        q.push({source, INF});
        fill(par.begin(), par.end(), -1);
        par[source] = -2;
        while(!q.empty()) {
            int cur = q.front().F;
            int f = q.front().S;
            q.pop();
            for(int& nxt : adj[cur]) {
                if(par[nxt] == -1 && cap[{cur, nxt}] - flow[{cur, nxt}] > 0) {
                    par[nxt] = cur;
                    int new_f = min(f, cap[{cur, nxt}] - flow[{cur, nxt}]);
                    if(nxt == sink)
                        return new_f;
                    q.push({nxt, new_f});
                }
            }
        }
        return 0;
    }
    int findMaxFlow(int source, int sink) {
        int totalFlow = 0;
        int f = 0;
        while((f = bfs(source, sink))) {
            totalFlow += f;
            int cur = sink;
            while(cur != source) {
                int prv = par[cur];
                flow[{prv, cur}] += f;
                flow[{cur, prv}] -= f;

                cur = prv;
            }
        }
        return totalFlow;
    }
};

void TC() {
	int n;
  int na, nb, nc;
  int number;
  int val;

  // 1. intput && 2. add edge

  scanf("%d", &n);
  
  scanf("%d%d%d", &na, &nb, &nc);

  unordered_set<int> sa;
  unordered_set<int> sb;
  unordered_set<int> sc;

  scanf("%d", &number);
  for (int i = 0; i < number; i++) {
      cin >> val;
      sa.insert(val);
  }

  scanf("%d", &number);
  for (int i = 0; i < number; i++) {
      cin >> val;
      sb.insert(val);
  }

  scanf("%d", &number);
  for (int i = 0; i < number; i++) {
      cin >> val;
      sc.insert(val);
  }

  unordered_set<int> gA;
  unordered_set<int> gB;
  unordered_set<int> gC;
  unordered_set<int> gAB;
  unordered_set<int> gBC;
  unordered_set<int> gCA;
  unordered_set<int> gABC;

  for (int i = 1; i <= n; i++) {
      int count_a = sa.count(i);
      int count_b = sb.count(i);
      int count_c = sc.count(i);

      if (count_a + count_b + count_c == 3) {
          gABC.insert(i);
      } else if (count_a + count_b == 2) {
          gAB.insert(i);
      } else if (count_b + count_c == 2) {
          gBC.insert(i);
      } else if (count_a + count_c == 2) {
          gCA.insert(i);
      } else if (count_a == 1) {
          gA.insert(i);
      } else if (count_b == 1) {
          gB.insert(i);
      } else if (count_c == 1) {
          gC.insert(i);
      }
  }

  MaxFlow mf(12);
  // 1: group A: group of A
  // 2: group B: group of B
  // 3: group C: group of C
  // 4: group AB: group of AB
  // 5: group BC: group of BC
  // 6: group CA: group of CA
  // 7: group ABC: group of ABC
  // 8: A
  // 9: B
  // 10: C
  // 11: source
  // 12: sink
  int source = 11;
  int sink = 12;

  // connect source to 1,2,3...7
  mf.addEdge(source, 1, gA.size());
  mf.addEdge(source, 2, gB.size());
  mf.addEdge(source, 3, gC.size());
  mf.addEdge(source, 4, gAB.size());
  mf.addEdge(source, 5, gBC.size());
  mf.addEdge(source, 6, gCA.size());
  mf.addEdge(source, 7, gABC.size());


  // connect 1,2,3...7 to A, B, C
  mf.addEdge(1, 8, gA.size());
  mf.addEdge(2, 9, gB.size());
  mf.addEdge(3, 10, gC.size());
  mf.addEdge(4, 8, gAB.size());
  mf.addEdge(4, 9, gAB.size());
  mf.addEdge(5, 9, gBC.size());
  mf.addEdge(5, 10, gBC.size());
  mf.addEdge(6, 10, gCA.size());
  mf.addEdge(6, 8, gCA.size());
  mf.addEdge(7, 8, gABC.size());
  mf.addEdge(7, 9, gABC.size());
  mf.addEdge(7, 10, gABC.size());

  // connect A, B, C to sink
  mf.addEdge(8, sink, na);
  mf.addEdge(9, sink, nb);
  mf.addEdge(10, sink, nc);

  // 3. output
  printf("%d\n", mf.findMaxFlow(source, sink));

  // Output flow
  for (int i = 0; i < mf.flow[{1, 8}]; i++) {
      printf("%d A\n", *(gA.begin()));
      gA.erase(gA.begin());
  }

  for (int i = 0; i < mf.flow[{2, 9}]; i++) {
      printf("%d B\n", *(gB.begin()));
      gB.erase(gB.begin());
  }

  for (int i = 0; i < mf.flow[{3, 10}]; i++) {
      printf("%d C\n", *(gC.begin()));
      gC.erase(gC.begin());
  }

  for (int i = 0; i < mf.flow[{4, 8}]; i++) {
      printf("%d A\n", *(gAB.begin()));
      gAB.erase(gAB.begin());
  }

  for (int i = 0; i < mf.flow[{4, 9}]; i++) {
      printf("%d B\n", *(gAB.begin()));
      gAB.erase(gAB.begin());
  }

  for (int i = 0; i < mf.flow[{5, 9}]; i++) {
      printf("%d B\n", *(gBC.begin()));
      gBC.erase(gBC.begin());
  }

  for (int i = 0; i < mf.flow[{5, 10}]; i++) {
      printf("%d C\n", *(gBC.begin()));
      gBC.erase(gBC.begin());
  }

  for (int i = 0; i < mf.flow[{6, 10}]; i++) {
      printf("%d C\n", *(gCA.begin()));
      gCA.erase(gCA.begin());
  }

  for (int i = 0; i < mf.flow[{6, 8}]; i++) {
      printf("%d A\n", *(gCA.begin()));
      gCA.erase(gCA.begin());
  }

  for (int i = 0; i < mf.flow[{7, 8}]; i++) {
      printf("%d A\n", *(gABC.begin()));
      gABC.erase(gABC.begin());
  }

  for (int i = 0; i < mf.flow[{7, 9}]; i++) {
      printf("%d B\n", *(gABC.begin()));
      gABC.erase(gABC.begin());
  }

  for (int i = 0; i < mf.flow[{7, 10}]; i++) {
      printf("%d C\n", *(gABC.begin()));
      gABC.erase(gABC.begin());
  }
}
int32_t main() {
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
		TC();
	
}

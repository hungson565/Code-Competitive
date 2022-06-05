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


#define MAX 1e6
#define INF 1e9 + 5

bool isPrime[100005];
vector<int> primes;
vector<int> check(100005, false);

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

    // get primes
    for (int x = 2; x <= 100000; x++) {
        if (isPrime[x]) {
            primes.push_back(x);
        }
    }

    // check state of each x (win: 1, loose: 0)
    check[0] = true;
    check[1] = true;
    for (int state = 2; state <= 100000; state++) {
        if (isPrime[state]) {
            check[state] = true;
            check[state + 1] = true;
        }
    }

    for (int state = 2; state <= 100000; state++) {
        if (check[state]) {
            continue;
        }
        for (int idx = 0; idx < primes.size(); idx++) {
            if (state + primes[idx] >= 100000) {
                break;
            }
            check[state + primes[idx]] = true;
        }
    }
}

void solve()
{
    int A, k;
    cin >> A >> k;
    
    vector<int> pre(100010, 0);
    pre[0] = 0;
    pre[1] = 0;
    pre[2] = 0;
    for (int i = 1; i < 100005; i++) {
        pre[i] = pre[i - 1];
        if (check[i] == false) {
            pre[i]++;
        }
    }

    int ans = 2;
    int maxVal = 0;
    for (int i = 2; i <= A - k + 1; i++) {
        if (pre[i + k - 1] - pre[i - 1] > maxVal) {
            ans = i;
            maxVal = pre[i + k - 1] - pre[i - 1];
        }
    }

    cout << maxVal << " " << ans << endl;

}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(100005);
    int T;
    cin >> T;
    while (T > 0)
    {
        solve();
        // cout << "T: " << T << endl;
        T--;
    }

    return 0;
}
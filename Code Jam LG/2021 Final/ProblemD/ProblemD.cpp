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

int n, m;
int v[100];
int dp[40111][20];
bool isPrime[6000111];
vector<int> primes;
int sum_dp[1 << 16];

int val[7000000];

void sieve() {
    for(int i = 0; i <= 6000000;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= 6000000; ++i) {
         if(isPrime[i] == true) {
             for(int j = i * i; j <= 6000000; j += i)
                 isPrime[j] = false;
        }
    }

    for (int i = 2; i <= 6000000; i++) {
      if (isPrime[i]) primes.push_back(i);
    }

    // cal val
    val[1] = 1;
    val[2] = 1;
    for (int i = 1; i < primes.size() - 1; i++) {
      int cur = primes[i];
      int last = primes[i - 1];
      int next = primes[i + 1];
      val[cur] = min(cur - last, next - cur);
    }

    for (int i = 0; i < primes.size() - 1; i++) {
      int first = primes[i];
      int second = primes[i + 1];
      for (int v = first + 1; v < second; v++) {
        val[v] = min(v - first, second - v);
      }
    }

}


int getVal(int a) {

  // binary search, Pass with 10^6.log(10^ 6)

  // int ans = INT_MAX;
  // int it = upper_bound(primes.begin(), primes.end(), a) - primes.begin();
  // ans = min(ans, primes[it] - a);
  // if (it > 0) {
  //   if (primes[it - 1] != a) {
  //     ans = min(ans, a - primes[it - 1]);
  //   } else {
  //     if (it > 1) {
  //       ans = min(ans, a - primes[it - 2]);
  //     }
  //   }
  // } 

  // return ans;

  return val[a];
}

int cal(int mask, int number) {
  if (dp[mask][number] != -1) {
    return dp[mask][number];
  }

  if (number == 1) {
    int sum = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        sum += v[i];
        ok = true;
      }
    }

    if (!ok) {
      dp[mask][number] = 0;
      return 0;
    }
    dp[mask][number] = getVal(sum);
    return dp[mask][number];
  }

  int ans = INT_MAX;
  int sub = (0-mask) & mask;

  do {
    int sum = 0;

      if (sum_dp[sub] != -1) {
        sum = sum_dp[sub];
      } else {
        for (int i = 0; i < n; i++) {
          if (sub & (1 << i)) {
            sum += v[i];
          }
        }
        sum_dp[sub] = sum;
      }

      // if not enough 1 for others, then break
      if (__builtin_popcount(mask - sub) < number - 1) break;

      // cal value in this case
      int v = max(getVal(sum), cal(mask - sub, number - 1)); 

      // get min of all values
      ans = min(ans, v);

  } while ((sub=(sub-mask) & mask));

  dp[mask][number] = ans;
  return dp[mask][number];
}

void solve()
{
    memset(sum_dp, -1, sizeof(sum_dp));
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << cal((1 << n) - 1, m) << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(val, 0, sizeof(val));

    sieve();

    int T;
    cin >> T;
    while (T > 0)
    {
        solve();
        T--;
    }

    return 0;
}
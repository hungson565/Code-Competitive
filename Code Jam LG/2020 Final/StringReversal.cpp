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


#define MAX 1e6
#define INF 1e9 + 5

bool isPrime[100005];
vector<int> primes;
vector<int> check(100005, false);

string reversE(const string& s) {
    string ans = s;
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve()
{
    int n; cin >> n;
    vector<string> arr(n);
    for (auto& s : arr) cin >> s;

    bool dp[n + 5][2];
    memset(dp, false, sizeof(dp)); // dp[i][0]: check if string from i -> n - 1 that start in order at i could make lexicographically 
                                   // dp[i][1]: check if string from i -> n - 1 that start NOT in order at i could make lexicographically 

    dp[n - 1][0] = true;
    dp[n - 1][1] = true;

    // dp[i][0], dp[i][1]
    for (int i = n - 2; i >= 0; i--) {
        if ((arr[i] <= arr[i + 1] && dp[i + 1][0]) || (arr[i] <= reversE(arr[i + 1]) && dp[i + 1][1])) {
            dp[i][0] = true;
        }
        if ((reversE(arr[i]) <= arr[i + 1] && dp[i + 1][0]) || (reversE(arr[i]) <= reversE(arr[i + 1]) && dp[i + 1][1])) {
            dp[i][1] = true;
        }
    }

    // trace
    string ans;
    int c;
    int last;

    if (dp[0][0] == true) {
        c = '0';
        last = 0;
    } else {
        c = '1';
        last = 1;
    }
    ans += c;

    for (int i = 1; i < n; i++) {
        if (dp[i][0]) {
            if ((last == 0 && arr[i] >= arr[i - 1]) || (last == 1 && arr[i] >= reversE(arr[i - 1]))) {
                c = '0';
                ans += c;
                last = 0;
                continue;
            }
        }
        c = '1';
        ans += c;
        last = 1;
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
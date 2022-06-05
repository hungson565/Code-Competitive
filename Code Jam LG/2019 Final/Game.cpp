// https://codejam.lge.com/problem/23024

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define INF 1e9 + 5
 
// Policy based data structure
typedef tree<int, null_type,
             less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;

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

const int MOD = 1e9 + 7;

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


int string2int(const string& s) {
    int ans = 0;
    for (auto c : s) {
        int pow = c - 'A';
        ans += (1 << pow);
    }
    return ans;
}

int cal(int a, int b) {
    if (a == 1 && b == 1) {
        return 0;
    }
    if (a == b) {
        return INF;
    }
    if (a > b) {
        return 1 + cal(a - b, b);
    } else {
        return 1 + cal(a, b - a);
    }
    return 0;
}

void solve()
{
    int x;
    cin >> x;

    int val = INT_MAX;
    int a, b;
    for (int i = 1; i <= x / 2; i++) {
        int v = cal(x, i);
        if (v < val) {
            val = v;
            a = x;
            b = i;
        }
    }

    string ans;
    for (int k = 1; k <= val; k++) {
        if (a > b) {
            ans += "R";
            a = a - b;
        } else {
            ans += "B";
            b = b - a;
        }
    }
    // reverse(ans.begin(), ans.end());
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
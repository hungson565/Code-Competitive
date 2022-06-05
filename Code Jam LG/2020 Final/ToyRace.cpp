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

// get index as an integer from
int string2int(const string& s) {
    int ans = 0;
    for (auto c : s) {
        ans += (1 << (c - 'A'));
    }
    return ans;
}

void solve() {
    int N, X, Y;
	cin >> N;
    cin >> X;
    cin >> Y;
    vector<int> v;
    int vv;
    for(int i = 0; i < N; ++i) {
        cin >> vv;
        v.push_back(vv);
    }
    int vmax = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (v[i] > vmax) {
            vmax = v[i];
        }
    }

    if (vmax < v[N-1]) {
        cout << "0" << endl;
        return;
    }

    // if (vmax > Y) {
    //     cout << -1 << endl;
    // }

    // cout << "vmax: " << vmax << endl;
    int Z = v[N-1] + X - ((X * v[N-1]) / vmax) + 1;
    if ((X * v[N-1]) % vmax != 0) {
        Z--;
    }

    if (Z > Y) {
        Z = -1;
    }
    cout << Z << endl;
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

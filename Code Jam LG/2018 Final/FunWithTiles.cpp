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

int cal(int len) {
    if (len % 2 == 0) {
        return 1;
    }
    if (len == 1) {
        return 1;
    }
    return len / 2 + 1;
}

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

void solve()
{
    int R;
    int C;
    int k;
    cin >> R >> C >> k;
    // scanf("%d", &R);
    // scanf("%d", &C);
    // scanf("%d", &k);

    vector<Point> points;
    int x1;
    int x2;
    for (int i = 0; i < k; i++) {
        cin >> x1 >> x2;
        // scanf("%d", &x1);
        // scanf("%d", &x2);
        points.push_back(Point(x1, x2));
    }

    unordered_set<int> row;
    for (auto p : points) {
        row.insert(p.x);
    }

    // cal in unsed rows
    int unused_row = R - row.size();
    int ans = 1;
    int ans0 = 0;

    if (C % 2 == 0) {
        ans = 1;
    } else {
        ans = pow(cal(C), unused_row);
    }
    ans0 = unused_row * (C / 2);

    // cal in used rows
    unordered_map<int, vector<int>> m;
    for (auto p : points) {
        m[p.x].push_back(p.y);
    }

    for (auto &e : m) {
        vector<int>& v = e.second;
        sort(v.begin(), v.end());
        v.push_back(C + 1);

        int last = 0;
        for (auto e : v) {
            ans = (ans * cal(e - last - 1)) % MOD;
            ans0 += (e - last - 1) / 2;
            last = e;
        }
    }

    cout << ans0 << " " << ans << endl;
    // printf("%lld %lld\n", ans0, ans);

}



int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T;
    // cin >> T;
    // while (T > 0)
    // {
        solve();
    //     T--;
    // }

    return 0;
}
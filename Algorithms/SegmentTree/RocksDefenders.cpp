// https://codeforces.com/contest/1679/problem/C

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


void solve()
{
    int n, q;
    cin >> n >> q;

    // Ordered_set sx, sy;

    vector<int> count_x(n + 1, 0);
    vector<int> count_y(n + 1, 0);

    vector<int> data_x(n + 1, 0);
    vector<int> data_y(n + 1, 0);
    ST st_x(data_x);
    ST st_y(data_y);

    for (int i = 0; i < q; i++) {
      int type;
      cin >> type;

      if (type == 1) {
        int x, y;
        cin >> x >> y;
        count_x[x]++;
        count_y[y]++;

        if (count_x[x] == 1) {
            st_x.modify(x, 1);
        }

        if (count_y[y] == 1) {
            st_y.modify(y, 1);
        }
      } else if (type == 2) {
        int x, y;
        cin >> x >> y;
        count_x[x]--;
        count_y[y]--;
        if (count_x[x] == 0)
            st_x.modify(x, 0);
        if (count_y[y] == 0)
            st_y.modify(y, 0);
      } else {
        int x1, y1, x2,  y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int rx = st_x.query(x1, x2);
        int ry = st_y.query(y1, y2);

        if ((rx == x2 - x1 + 1) || (ry == y2 - y1 + 1)) {
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }

      }
    }

}



int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    solve();
    return 0;
}
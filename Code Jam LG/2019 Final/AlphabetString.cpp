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
        ans += 1 << (c - 'A');
    }
    // cout << "check s: " << s << ", ans: " << ans << endl;
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    string window;
    int n = s.size();
    vector<bool> check((1 << 26) + 5, false);

    int ANS = 0;

    for (int i = 0; i < n; i++) {
        int idx = -1;
        for (int j = 0; j < window.size(); j++) {
            if (window[j] == s[i]) {
                idx = j;
                break;
            }
        }
        string new_window = "";
        if (idx == -1) {
            new_window = window;
        } else {
            for (int j = 0; j < window.size(); j++) {
                if (j != idx)
                    new_window += window[j];
            }
        }

        new_window += s[i];
        window = new_window;

        string val = "";
        for (int j = (int) window.size() - 1; j >= 0; j--) {
            val += window[j];
            if (check[v] != true) {
                check[v] = true;
                ANS++;
            }
        }

    }

    // int cnt = 0;
    // for (auto e : ans) {
    //     if (e == true) {
    //         cnt++;
    //     }
    // }
    // for (int i = 0; i < 100; i++) {
    //     if (ans[i] == true) {
    //         cnt++;
    //     }
    // }
    cout << ANS << "\n";

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
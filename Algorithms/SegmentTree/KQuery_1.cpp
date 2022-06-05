// https://www.spoj.com/problems/KQUERY/

#include <bits/stdc++.h>
using namespace std;

class ST {
  int n;
  vector<vector<int>> tree;
public:
  ST(const vector<int>& data) {
    int N = data.size();
    n = N;
    tree.resize(2 * n);
    for (int i = 0; i < n; i++) {
      tree[i + n] = {data[i]};
    }
    build();
  }

  void build() {  // build the tree
    for (int i = n - 1; i > 0; --i)  merge(tree[i<<1].begin(), tree[i<<1].end(), tree[i<<1|1].begin(), tree[i<<1|1].end(), back_inserter(tree[i]));
  }

  // void modify(int p, int value) {  // set value at position p
  //   for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = tree[p] + tree[p^1];
  // }

  int query(int l, int r, int k) {  // sum on interval [l, r]
    r++;
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) {
        res += tree[l].end() - upper_bound(tree[l].begin(), tree[l].end(), k);
        l++;
      }
      if (r&1) {
        r--;
        res += tree[r].end() - upper_bound(tree[r].begin(), tree[r].end(), k);
      }
    }
    return res;
  }  
};
/*
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 
*/

int main() {
  int N;
  cin >> N;

  vector<int> data;
  int val;

  for (int i = 0; i < N; i++) {
    cin >> val;
    data.push_back(val);
  }

  int M;
  cin >> M;
  int l, r, k;
  ST st(data);

  for (int i = 0; i < M; i++) {
      cin >> l >> r >> k;
      cout << st.query(l - 1, r - 1, k) << endl;
  }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

/*
const int N = 1e5;  // limit for array size
int n;  // array size
int tree[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) tree[i] = tree[i<<1] + tree[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = tree[p] + tree[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += tree[l++];
    if (r&1) res += tree[--r];
  }
  return res;
}
*/

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
    for (int i = n - 1; i > 0; --i) tree[i] = min(tree[i<<1], tree[i<<1|1]);
  }

  void modify(int p, int value) {  // set value at position p
    for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = min(tree[p], tree[p^1]);
  }

  int query(int l, int r) {  // sum on interval [l, r]
    r++;
    int res = INT_MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = min(res, tree[l++]);
      if (r&1) res = min(res, tree[--r]);
    }
    return res;
  }  
};

int main() {
  int n;
  vector<int> data = {0,1,2,3,4,5,6,7,8};
  ST st(data);
  st.modify(0, 10);
  printf("%d\n", st.query(3, 4));
  st.modify(4, 20);
  printf("%d\n", st.query(1, 6));
  return 0;
}

// https://www.spoj.com/problems/KQUERY/

#include <bits/stdc++.h>
using namespace std;

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

/*
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 
*/

struct Query {
  int l;
  int r;
  int k;
  int ans;
};

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
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

  vector<Query> queries;

  for (int i = 0; i < M; i++) {
      cin >> l >> r >> k;
      queries.push_back(Query{l - 1, r - 1, k});
  }

  vector<int> id_q(M);
  for (int i = 0; i < M; i++) {
    id_q[i] = i;
  }

  sort(id_q.begin(), id_q.end(), [&queries](int i1, int i2) {
    return queries[i1].k < queries[i2].k;
  });

  vector<int> b(N, 1);
  ST st(b);
  vector<int> id(N);
  for (int i = 0; i < N; i++) {
    id[i] = i;
  }
  sort(id.begin(), id.end(), [&data](int id1, int id2) {
    return data[id1] < data[id2];
  });
  int i_id = 0;
  for (int i = 0; i < M; i++) {
    Query& q = queries[id_q[i]];
    while (i_id < N && data[id[i_id]] <= q.k) {
      b[i_id] = 0;
      st.modify(id[i_id], 0);
      i_id++;
    }
    q.ans = st.query(q.l, q.r);
  }

  for (auto q : queries) {
    cout << q.ans << endl;
  }

  return 0;
}

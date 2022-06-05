#include <bits/stdc++.h>
using namespace std;

class STree {

  int n;
  vector<int> tree;

  STree(const vector<int>& data) {
    int N = data.size();
    n = N;
    tree.resize(n + 1);
    for (int i = 0; i < n; i++) {
      tree[i + n] = data[i];
    }
    // build();
  }

  // Truy vấn: A(i) = v
  // Hàm cập nhật trên cây tree, cập nhật cây con gốc id quản lý đọan [l, r]
  void update(int id, int l, int r, int i, int v) {
      if (i < l || r < i) {
          // i nằm ngoài đoạn [l, r], ta bỏ qua nút i
          return ;
      }
      if (l == r) {
          // Đoạn chỉ gồm 1 phần tử, không có nút con
          tree[id] = v;
          return ;
      }

      // Gọi đệ quy để xử lý các nút con của nút id
      int mid = (l + r) / 2;
      update(id*2, l, mid, i, v);
      update(id*2 + 1, mid+1, r, i, v);

      // Cập nhật lại giá trị max của đoạn [l, r] theo 2 nút con:
      tree[id] = max(tree[id*2], tree[id*2 + 1]);
  }

  // Truy vấn: tìm max đoạn [u, v]
  // Hàm tìm max các phần tử trên cây tree nằm trong cây con gốc id - quản lý đoạn [l, r]
  int get(int id, int l, int r, int u, int v) {
      if (v < l || r < u) {
          // Đoạn [u, v] không giao với đoạn [l, r], ta bỏ qua đoạn này
          return -INFINITY;
      }
      if (u <= l && r <= v) {
          // Đoạn [l, r] nằm hoàn toàn trong đoạn [u, v] mà ta đang truy vấn, ta trả lại
          // thông tin lưu ở nút id
          return tree[id];
      }
      int mid = (l + r) / 2;
      // Gọi đệ quy với các con của nút id
      return max(get(id*2, l, mid, u, v), get(id*2 + 1, mid+1, r, u, v));
  }

};

int main() {
  int n;
  vector<int> data = {0,1,2,3,4,5,6,7,8};
  STree st(data);
  st.modify(0, 10);
  printf("%d\n", st.query(3, 4));
  st.modify(4, 20);
  printf("%d\n", st.query(1, 6));
  return 0;
}

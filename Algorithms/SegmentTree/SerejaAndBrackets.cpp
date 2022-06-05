// https://codeforces.com/contest/380/problem/C

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int optimal;
    int open;
    int close;

    Node(int opt = 0, int o = 0, int c = 0) { // Khởi tạo struct Node
        optimal = opt;
        open = o;
        close = c;
    }
};

Node operator + (const Node& left, const Node& right) {
    Node res = {0, 0, 0};
    // min(số dấu "(" thừa ra ở cây con trái, và số dấu ")" thừa ra ở cây con phải)
    int tmp = min(left.open, right.close);

    // Để xây dựng kết quả tối ưu ở nút id, ta nối dãy ngoặc tối ưu ở 2 con, rồi thêm
    // min(số "(" thừa ra ở con trái, số ")" thừa ra ở con phải).
    res.optimal = left.optimal + right.optimal + 2 * tmp;

    res.open = left.open + right.open - tmp;
    res.close = left.close + right.close - tmp;

    return res;
}

/*
())(())(())(
7
5 6
5 7
5 8
5 9
5 10
5 11
2 10

*/

class ST {
  int n;
  vector<Node> tree;
public:
  ST(const string& s) {
    int N = s.size();
    n = N;
    tree.resize(2 * n);
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        tree[i + n] = Node(0, 1, 0);
      }
      else {
        tree[i + n] = Node(0, 0, 1);
      }
    }
    build();
  }

  void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) tree[i] = tree[i<<1] + tree[i<<1|1];
  }

  // void modify(int p, int value) {  // set value at position p
  //   for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = tree[p] + tree[p^1];
  // }

  int query(int l, int r) {  // sum on interval [l, r]
    r++;
    Node res(0, 0, 0);
    deque<Node> operand1;
    deque<Node> operand2;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) {
          operand1.push_back(tree[l++]);
          
      }
      if (r&1) {
          operand2.push_front(tree[--r]);
          
      }
    }
    Node o;
    while (!operand1.empty()) {
        o = operand1.front();
        operand1.pop_front();
        res = res + o;
    }
    while (!operand2.empty()) {
        o = operand2.front();
        operand2.pop_front();
        res = res + o;
    }
    return res.optimal;
  }  
};

int main() {
  string s;
  cin >> s;
  
  int M;
  cin >> M;

  ST st(s);
  int l, r;
  for (int i = 0; i < M; i++) {
    cin >> l >> r;
    cout << st.query(l - 1, r - 1) << endl;
  }

  return 0;
}

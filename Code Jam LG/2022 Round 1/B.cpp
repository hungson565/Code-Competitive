#include <iostream>

// C++ Program to implement the
// above approach
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
// Make __builtin_popcount faster: https://codeforces.com/blog/entry/13134?#comment-736517
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

// Ordered set
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type,
             less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;

// MACRO
#define int long long
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)

#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int)(x).size())
#define ALL(a) (a).begin(), (a).end()
#define TWO(x) (1LL<<(x))
inline int gcd(int a, int b) {int r; while (b) {r = a % b; a = b; b = r;} return a;}

// For printing pair, container, etc.
// Copied from https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
template<class U, class V> ostream& operator << (ostream& out, const pair<U, V>& p) {
    return out << '(' << p.first << ", " << p.second << ')';
}
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator << (ostream& out, const Con& con) {
    out << '{';
    for (auto beg = con.begin(), it = beg; it != con.end(); it++) {
        out << (it == beg ? "" : ", ") << *it;
    }
    return out << '}';
}

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

// ----------------------------------------------
// ideal




#define MAXN   1000009
 
// stores smallest prime factor for every number
// int spf[MAXN];
vector<int> spf(MAXN);

vector<vector<int>> dic(MAXN);
 
// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}




// ----------------------------------------------

/*

4
4
5 1 3 2
4
10 8 5 7
7
1 2 3 100 10 20 30
7
1000 1000 1000 1000 1000 1000 1000

*/

// Input, output
#include <iostream>
string file_name = "ProblemA.in";
ifstream input;
#include <string>

#define M 1000
// #define int int64_t


/*

7
2 1 20 22
2 2 20 22
3 3 008 258
3 22 008 258
4 10 2022 3141
4 61 2022 3141
4 1000000000000000000 0000 9999

*/

void solve() {
  int l, k, x, y;
  cin >> l >> k >> x >> y;

  int n = pow(10, l);

  // vertex
  vector<int> v(n);

  // edges
  vector<set<int>> e(n);

  // create edges
  for (int i = 0; i < n; i++) {
    string v_str = to_string(i);
    int size = v_str.size();
    for (int j = 0; j < l - size; j++) {
      v_str = "0" + v_str;
    }

    // cout << "v_str: " << v_str << endl;

    // find neighbors
    vector<string> neighbors;
    for (int j = 0; j < l; j++) {
      if (v_str[j] == '0') {
        string neighbor = v_str;
        neighbor[j]++;
        neighbors.push_back(neighbor);
      } else if (v_str[j] == '9') {
        string neighbor = v_str;
        neighbor[j]--;
        neighbors.push_back(neighbor);
      } else {
        string neighbor = v_str;
        neighbor[j]--;
        neighbors.push_back(neighbor);

        neighbor[j] += 2;
        neighbors.push_back(neighbor);
      }
    }

    // connect to neighbor
    // cout << "neighbor of i: " << i << " --- ";
    for (auto neighbor : neighbors) {
      int neighbor_int = stoi(neighbor);
      e[i].insert(neighbor_int);
      e[neighbor_int].insert(i);
      // cout << neighbor << " ";
    }
    // cout << endl;

  }


  // bfs from y to other node

  queue<int> q;
  q.push(y);

  vector<int> dis(n, INT_MAX);
  dis[y] = 0;
  while (!q.empty()) {
    int element = q.front();
    q.pop();
    for (auto neighbor : e[element]) {
      if (dis[neighbor] == INT_MAX) {
        dis[neighbor] = dis[element] + 1;
        q.push(neighbor);
        // cout << element << " push " << neighbor << endl;
      }
    }
  }
  // cout << "dis from x to y: " << dis[x] << endl;

  // for (int i = 0; i < n; i++) {
  //     cout << dis[i] << " ";
  // }
  // cout << endl;

  // cout << dis[y] << endl;

  vector<int> dp(n, 0);
  dp[y] = 1;
  // q.clear();
  q.push(y);
  vector<bool> flag(n, false);
  flag[y] = true;
  while (!q.empty()) {
    int element = q.front();
    q.pop();
    // cout << "--> element: " << element << endl;
    for (auto neighbor : e[element]) {
      if (dis[neighbor] == dis[element] - 1) {
        dp[element] += dp[neighbor];
        // cout << "plus: " << dp[neighbor] << endl;
      } else if (flag[neighbor] == false) {
        q.push(neighbor);
        flag[neighbor] = true;
        // cout << "push " << neighbor << endl;
      }
    }

  }
  // cout << "dp[x]: " << dp[x] << endl;
 


  if (k > dp[x]) {
    cout << "NO" << endl;
    return;
  }

  int src = x;
  int dst = y;

  int stt = k;

  int count_log = 0;

  vector<string> ans;

  string v_str = to_string(src);
  // cout << "v_str before: " << v_str << ", src: " << src << ", size: " << v_str.size() << endl;
  int size = v_str.size();
  for (int j = 0; j < l - size; j++) {
    v_str = "0" + v_str;
  }
  ans.push_back(v_str);
  // cout << "v_str: " << v_str << ", src: " << src << endl;

  while (src != dst) {
    int next_src;
    for (auto next_src : e[src]) {
      if (dis[next_src] != dis[src] - 1) {
        continue;
      }
      count_log++;
      if (dp[next_src] < stt) {
        // if (count_log < 20)
        //   cout << "next_src small: " << next_src << endl;
        stt -= dp[next_src];
      } else {
        // src = next_src;
        // if (count_log < 20)
        //   cout << "next_src break: " << next_src << endl;
        src = next_src;

        string v_str = to_string(src);
        int size = v_str.size();
        for (int j = 0; j < l - size; j++) {
          v_str = "0" + v_str;
        }
        ans.push_back(v_str);

        break;
      }
    }
    // src = next_src;
    // if (count_log < 20)
    // cout << "src: " << src << endl;
  }

  // cout << "END" << endl;

  for (auto s : ans) {
    cout << s << " ";
  }
  cout << endl;

}

map<vector<int>, TrieNode*> m;

vector<int>& getFactorization(int x)
{
  if (!dic[x].empty()) {
    return dic[x];
  }
  vector<int> ret;
  while (x != 1)
  {
      ret.push_back(spf[x]);
      x = x / spf[x];
  }
  dic[x] = ret;
  return dic[x];
}

struct TrieNode {
  // unordered_map<int, TrieNode* > children;
  // vector<TrieNode* > children;
	int isEndOfWord = 0;
  int sum = 0;
  int count = 0;
  // int val = 0;
};

TrieNode* getNode() {
  return new TrieNode();
}

class Trie {
  public:
  TrieNode *root;
  Trie() {
    root = getNode();
  }

  void insert(int e) {
    // cout << "insert e " << e << endl;
    auto& pFactors = getFactorization(e);
    struct TrieNode *pCrawl = root;

    pCrawl->count++;

    int val = 0;
    for (int j = pFactors.size() - 1; j >= 0; j--) {
      val += pFactors[j];
    }

    for (int i = pFactors.size() - 1; i >= 0; i--) {
      int element = pFactors[i];

      TrieNode* next = nullptr;

      if (!m.count({(int)pCrawl, element})) {
        next = getNode();
        m[{(int)pCrawl, element}] = next;
      } else {
        next = m[{(int)pCrawl, element}];
      }

      // m2[{(int)next}] = next;

      pCrawl->sum += val;
      val -= pFactors[i];
      // pCrawl = pCrawl->children[element];
      // if (next == nullptr) {
      //   cout << "NULLLLLLLLL" << endl;
      // }
      pCrawl = next;
      pCrawl->count++;
      
    }
    pCrawl->isEndOfWord++;

  }

  int search(int e) {
    // cout << "->search " << e << endl;
    struct TrieNode *pCrawl = root;
    auto& pFactors = getFactorization(e);

    int ans = 0;

    int current_val = 0;
    for (int j = pFactors.size() - 1; j >= 0; j--) {
      current_val += pFactors[j];
    }

    for (int i = pFactors.size() - 1; i >= 0; i--) {
      int element = pFactors[i];
      int sum_branch = 0;

      TrieNode* next;// = m[{pCrawl, element}];

      auto it = m.find({(int)pCrawl, element});

      if (it ==m.end()) {
        continue;
      } else {
        next = it->second;
      }

      // int count = pCrawl->count - pCrawl->children[element]->count - pCrawl->isEndOfWord;
      // sum_branch = pCrawl->sum - (pCrawl->children[element]->sum + pCrawl->children[element]->count * element);

      int count = pCrawl->count - next->count - pCrawl->isEndOfWord;
      sum_branch = pCrawl->sum - (next->sum + next->count * element);

      ans += current_val * count + sum_branch;

      // cout << "ans here: " << ans << endl;
      if (pCrawl->isEndOfWord) {
        ans +=  (pCrawl->isEndOfWord) * (current_val) ;
      
      }
      pCrawl = next;
      current_val -= pFactors[i];
    }

    ans += pCrawl->sum;
    return ans;
  }
};

// 2 1 20 22
// 2 3 37 55

int32_t  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    sieve();
    

    cin >> t;
    for (int i = 0; i < t; i++) {
      solve();
    }

    return 0;
}

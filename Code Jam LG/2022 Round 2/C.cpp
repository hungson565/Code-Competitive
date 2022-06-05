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
#define int int64_t
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


// ----------------------------------------------
// ideal




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

6
3
10 15 25
4
24 36 20 30
6
10 20 30 30 20 10
4
12 18 24 36
8
10 10 20 20 20 30 30 30
4
1 1 1 2

*/


#define MAXN   1000009
 
// stores smallest prime factor for every number
// int spf[MAXN];
vector<int> spf(MAXN);

// vector<vector<int>> dic(MAXN);
 
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

vector<int> getFactorization(int x)
{
  // if (!dic[x].empty()) {
  //   return dic[x];
  // }
  vector<int> ret;
  while (x != 1)
  {
      ret.push_back(spf[x]);
      x = x / spf[x];
  }
  // dic[x] = ret;
  return ret;
}

struct TrieNode {
  unordered_map<int, TrieNode* > children;
	int isEndOfWord = 0;
  int sum = 0;
  int count = 0;
};

TrieNode* getNode() {
  return new TrieNode();
}

class Trie {
  public:
  TrieNode *root;
  // unordered_set<TrieNode* > s;
  Trie() {
    root = getNode();
  }
  // ~Trie() {
    // for (auto e : s) {
    //   delete e;
    // }
  // }

  void insert2(int e, vector<TrieNode* >& vec, int& index) {
    // cout << "insert e " << e << endl;
    auto pFactors = getFactorization(e);
    struct TrieNode *pCrawl = root;

    pCrawl->count++;

    int val = 0;
    for (int j = pFactors.size() - 1; j >= 0; j--) {
      val += pFactors[j];
    }

    // for (int i = pFactors.size() - 1; i >= 0; i--) {
    //   int element = pFactors[i];
    //   if (!pCrawl->children.count(element)) {
    //     // pCrawl->children[element] = getNode();

    //     if (index < vec.size()) {
    //       pCrawl->children[element] = vec[index];
    //       index++;
    //     } else {
    //       pCrawl->children[element] = getNode();
    //     }
        
    //   }

    //   // int val = 0;
    //   // for (int j = i; j >= 0; j--) {
    //   //   val += pFactors[j];
    //   // }
    //   pCrawl->sum += val;
    //   val -= pFactors[i];
    //   pCrawl = pCrawl->children[element];
    //   pCrawl->count++;
      
    // }
    // pCrawl->isEndOfWord++;

  }
  
  void insert(int e, vector<TrieNode* >& vec, int& index) {
    // cout << "insert e " << e << endl;
    auto pFactors = getFactorization(e);
    struct TrieNode *pCrawl = root;

    pCrawl->count++;

    int val = 0;
    for (int j = pFactors.size() - 1; j >= 0; j--) {
      val += pFactors[j];
    }

    for (int i = pFactors.size() - 1; i >= 0; i--) {
      int element = pFactors[i];
      if (!pCrawl->children.count(element)) {
        // pCrawl->children[element] = getNode();

        if (index < vec.size()) {
          pCrawl->children[element] = vec[index];
          index++;
        } else {
          pCrawl->children[element] = getNode();
        }
        
      }

      // int val = 0;
      // for (int j = i; j >= 0; j--) {
      //   val += pFactors[j];
      // }
      pCrawl->sum += val;
      val -= pFactors[i];
      pCrawl = pCrawl->children[element];
      pCrawl->count++;
      
    }
    pCrawl->isEndOfWord++;

  }

  int search(int e) {
    // cout << "->search " << e << endl;
    struct TrieNode *pCrawl = root;
    auto pFactors = getFactorization(e);

    int ans = 0;

    int current_val = 0;
    for (int j = pFactors.size() - 1; j >= 0; j--) {
      current_val += pFactors[j];
    }

    for (int i = pFactors.size() - 1; i >= 0; i--) {
      int element = pFactors[i];
      int sum_branch = 0;
      int count = pCrawl->count - pCrawl->children[element]->count - pCrawl->isEndOfWord;
      sum_branch = pCrawl->sum - (pCrawl->children[element]->sum + pCrawl->children[element]->count * element);

      ans += current_val * count + sum_branch;

      // cout << "ans here: " << ans << endl;
      if (pCrawl->isEndOfWord) {
        ans +=  (pCrawl->isEndOfWord) * (current_val) ;
      
      }
      pCrawl = pCrawl->children[element];
      current_val -= pFactors[i];
    }

    ans += pCrawl->sum;
    return ans;
  }

  int search2(int e) {
    // cout << "->search " << e << endl;
    // struct TrieNode *pCrawl = root;
    // auto pFactors = getFactorization(e);

    // int ans = 0;

    // int current_val = 0;
    // for (int j = pFactors.size() - 1; j >= 0; j--) {
    //   current_val += pFactors[j];
    // }

    // for (int i = pFactors.size() - 1; i >= 0; i--) {
    //   int element = pFactors[i];
    //   int sum_branch = 0;
    //   int count = pCrawl->count - pCrawl->children[element]->count - pCrawl->isEndOfWord;
    //   sum_branch = pCrawl->sum - (pCrawl->children[element]->sum + pCrawl->children[element]->count * element);

    //   ans += current_val * count + sum_branch;

    //   // cout << "ans here: " << ans << endl;
    //   if (pCrawl->isEndOfWord) {
    //     ans +=  (pCrawl->isEndOfWord) * (current_val) ;
      
    //   }
    //   pCrawl = pCrawl->children[element];
    //   current_val -= pFactors[i];
    // }

    // ans += pCrawl->sum;
    // return ans;
    return 0;
  }
};
/*
6
3
10 15 25
4
24 36 20 30
*/

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> data;
  int val;
  for (int i = 0; i < n; i++) {
    scanf("%d", &val);
    data.push_back(val);
  }

  Trie tree;


  vector<TrieNode* > vec(n * 30);
  for (int i = 0; i < n * 30; i++) {
    auto t = getNode();
    vec[i] = t;
  }
  int index = 0;


  int count_1 = 0;
  for (auto e : data) {
    if (e == 1) {
      count_1++;
    } else
      tree.insert(e, vec, index);
  }

  int sum = 0;
  for (auto e : data) {
    if (e != 1) {
      int val = tree.search(e);
      sum += val;
    }
  }
  sum = sum / 2;

  int bonus_sum = 0;
  for (auto e : data) {
    if (e != 1) {
      auto pFactors = getFactorization(e);
      for (auto p : pFactors) {
        bonus_sum += p;
      }
    } 
  }
  sum += bonus_sum * count_1;

  // cout << "count 1: " << count_1 << endl;
  // cout << "SUM: " << sum << endl;


  // CASE 1: delete not 1

  // int pick = 0;
  int val_pick = 0;
  for (auto e : data) {
    int val;
    if (e != 1) {
      val = tree.search(e);

      auto pFactors = getFactorization(e);
      int bonus = 0;
      for (auto p : pFactors) {
        bonus += p;
      }

      val += bonus * count_1;
      val_pick = max(val_pick, val);
    } else {
      val_pick = max(val_pick, bonus_sum);
    }
  }

  sum -= val_pick;
  // cout << "ANSNNNNNNNNNNNNN: " << sum << endl;
  printf("%lld\n", sum);

  for (auto e : vec) {
    delete e;
  }

  {

    int n = 500000;
    vector<int> data;
    for (int i = 0; i < n; i++) {
      data.push_back(i + 5);
    }

    Trie tree;

    vector<TrieNode* > vec2(n);
    for (int i = 0; i < n; i++) {
      // auto t = getNode();
      // vec2[i] = t;
    }
    int index = 0;


    // int count_1 = 0;
    // for (auto e : data) {
    //   if (e == 1) {
    //     count_1++;
    //   } else
    //     tree.insert2(e, vec, index);
    // }

    // // int sum = 0;
    // // for (auto e : data) {
    // //   if (e != 1) {
    // //     int val = tree.search2(e);
    // //     sum += val;
    // //   }
    // // }
    // // sum = sum / 2;

     for (auto e : vec2) {
      delete e;
    }

  }

}

// 2 1 20 22
// 2 3 37 55
/*
3
10 15 25
4
24 36 20 30
*/

int32_t  main() {
    sieve();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
      solve();
    }

    return 0;
}

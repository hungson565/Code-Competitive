// #include <bits/stdc++.h>
// using namespace std;

// /*

// 7
// abcdbbd
// 4
// 2 3 6
// 1 3 b
// 2 1 1
// 2 3 6

// */

// class ST {
//   int n;
//   vector<vector<int>> tree;
// public:
//   ST(const string& data) {
//     int N = data.size();
//     n = N;
//     tree.resize(2 * n);
//     for (int i = 0; i < 2 * n; i++) {
//         tree[i] = vector<int>(26, 0);
//     }
//     for (int i = 0; i < n; i++) {
//       tree[i + n][data[i] - 'a'] = 1;
//     }
//     build();
//   }

//   void build() {  // build the tree
//     for (int c = 0; c < 26; c++) {
//         for (int i = n - 1; i > 0; --i) {
//             tree[i][c] = tree[i<<1][c] + tree[i<<1|1][c];
//         }
//     }
//   }

//   void modify(int p, int value, int c) {  // set value at position p
//         for (tree[p += n][c] = value; p > 1; p >>= 1) {
//             tree[p>>1][c] = tree[p][c] + tree[p^1][c];
//         }
//   }

//   int query(int l, int r, int c) {  // sum on interval [l, r]
//     r++;
//     int res = 0;
//     for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
//         if (l&1) res += tree[l++][c];
//         if (r&1) res += tree[--r][c];
//     }

//     return res;
//   }  
// };
 
// // Driver Code
// int main()
// {

//     int n;
//     string s;
//     int q;

//     scanf("%d", &n);
//     cin >> s;
//     scanf("%d", &q);

//     ST st(s);

//     int code;
//     for (int i = 0; i < q; i++) {
//         scanf("%d", &code);
//         if (code == 1) {
//             // Type1: change query
//             int pos;
//             char c;
//             scanf("%d", &pos);
//             scanf(" %c", &c);
//             pos--;
//             st.modify(pos, 1, c - 'a');
//             st.modify(pos, 0, s[pos] - 'a');
//             s[pos] = c;

//         } else {
//             // Type2: get query
//             int pos1, pos2;
//             scanf("%d", &pos1);
//             scanf("%d", &pos2);
//             pos1--;
//             pos2--;
//             int count = 0;
//             for (int c = 0; c < 26; c++) {
//                 int val = st.query(pos1, pos2, c);
//                 if (val > 0) {
//                     count++;
//                 }
//             }
//             printf("%d\n", count);
//         }
//     }
 
//     return 0;
// }

// /*

#include <bits/stdc++.h>
using namespace std;
// #define int long long

/*

7
abcdbbd
4
2 3 6
1 3 b
2 1 1
2 3 6

*/
 
// Driver Code
int main()
{

    int n;
    string s;
    int q;

    
    scanf("%d", &n);
    cin >> s;
    // char s1[n + 1];
    // scanf("%s", s1);
    // s = string(s1);
    scanf("%d", &q);

    vector<set<int>> ss(26);
    for (int i = 0 ; i < n; i++) {
        int c = s[i] - 'a';
        ss[c].insert(i);
    }

    int code;
    for (int i = 0; i < q; i++) {
        scanf("%d", &code);
        if (code == 1) {
            // Type1: change query
            int pos;
            char c;
            scanf("%d", &pos);
            scanf(" %c", &c);
            pos--;
            ss[s[pos] - 'a'].erase(pos);
            ss[c - 'a'].insert(pos);
            s[pos] = c;

        } else {
            // Type2: get query
            int pos1, pos2;
            scanf("%d", &pos1);
            scanf("%d", &pos2);
            pos1--;
            pos2--;
            int count = 0;
            for (int c = 0; c < 26; c++) {
                auto it2 = ss[c].upper_bound(pos2);
                auto it1 = ss[c].lower_bound(pos1);
                if (it2 != it1) {
                    count++;
                }
            }
            printf("%d\n", count);
        }
    }
 
    return 0;
}


// */
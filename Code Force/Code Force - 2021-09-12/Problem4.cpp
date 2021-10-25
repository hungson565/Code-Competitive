// https://codeforces.com/contest/1566/problem/D1
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// Policy based data structure
typedef tree<int, null_type,
             less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;

int T;
int k;

/*
4
1 3
1 2 3
1 5
2 1 5 3 3
1 2
2 1
1 6
2 3 2 1 1 1

*/


void solve() {
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<int> data;
    int val;
    for (int i = 0; i < m; i++) {
        cin >> val;
        data.push_back(val);
    }

    Ordered_set s;
    int64_t ans = 0;
    for (int i = 0; i < m; i++) {
        s.insert(data[i]);
        ans += (int64_t) s.order_of_key(data[i]);
    }
    cout << ans << endl;


}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

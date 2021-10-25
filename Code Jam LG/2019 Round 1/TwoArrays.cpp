// https://codejam.lge.com/problem/17124
// build: g++ -o TwoArrays TwoArrays.cpp -std=c++11 && TwoArrays

/*

3
4 3
20 5 14 9
16 8 12
3 4
16 8 12
20 5 14 9
3 3
1 2 3
2 3 4

*/


#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int m;
        int n;
        cin >> m;
        cin >> n;
        vector<int> a;
        vector<int> b;
        vector<int> c;
    
        int val;
        for (int i = 0; i < m; i++) {
            cin >> val;
            a.push_back(val);
        }
        for (int i = 0; i < n; i++) {
            cin >> val;
            b.push_back(val);
        }

        sort(b.begin(), b.end());

        for (int i = 0; i < m; i++) {
            auto it = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            if (it == n) {
                it--;
                c.push_back(b[it]);
            } else if (it == 0) {
                c.push_back(b[it]);
            } else {
                auto it2 = it - 1;
                if (b[it] - a[i] < a[i] - b[it2]) {
                    c.push_back(b[it]);
                } else {
                    c.push_back(b[it2]);
                }
            }
        }

        int64_t ans = 0;
        for (auto e : c) {
            ans += (int64_t) (e);
        }
        cout << ans << endl;
    }
    return 0;
}

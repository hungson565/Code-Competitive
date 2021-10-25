// build: g++ -o ProblemA ProblemA.cpp -std=c++11 && ProblemA

#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <deque>

// C++ Program to implement the
// above approach
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type,
             less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;

// Input, output
#include <iostream>
string file_name = "ProblemC.in";
ifstream input;

void solve() {
    // code here
    int n;
    input >> n;
    int X;
    int y;
    int Z;

    cin >> X;
    cin >> y;
    cin >> Z;

    vector<int> data;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        data.push_back(val);
    }

    vector<int64_t> prefix(n, 0);
    prefix[0] = data[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + data[i];
    }

    // need to find begin, end index / 
    // 1. (prefix[end] - prefix[begin - 1] = sum)
    // 2. sum - y * (end - begin + 1) >= Z
    // 3. (end - begin + 1) * y <= X

    // end - begin = ans, let binary search

    int ans = 0;
    int b = 0;
    int e = n + 1;
    ans = (b + e + 1) / 2;

    while (b < e) {
        // check ans


        if (check) {
            
        }
        ans = (b + e + 1) / 2; 
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    set<int> a;

    input.open(file_name);

    input >> t;
    while (t--) {
        solve();
    }

    input.close();
    return 0;
}

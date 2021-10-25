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
string file_name = "ProblemB.in";
ifstream input;

bool checkNumber(int N) {
    int count = 0;
    while (N > 0) {
        if ((N % 10) % 2 == 1) {
            count++;
        }
        N /= 10;
    }
    return count % 2 == 1;
}

void solve() {
    // code here
    int n;
    input >> n;
    vector<int> data;
    int val;
    for (int i = 0; i < n; i++) {
        input >> val;
        data.push_back(val);
    }

    sort(data.begin(), data.end());
    
    vector<bool> dic(200005, false);
    for (int i = 0; i < 200005; i++) {
        if (checkNumber(i)) {
            dic[i] = true;
        }
    }

    vector<vector<int64_t>> dp(101, vector<int64_t>(200005, 0));

    dp[0][data[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            for (int state = 0; state <= (j + 1) * 2000; state++) {
                if (dp[j][state] != 0) {
                // if (dic[(state + data[i])]) {
                    dp[i][state + data[i]] += dp[j][state];
                    cout << "i: " << i << ", j: " << j << ", state: " << state + data[i] << ", adding.. " << dp[j][state] << endl;
                    auto it = lower_bound(data.begin(), data.begin() + j - 1, data[j]) - data.begin();

                }
                // }
                // dp[i][state + data[i]] += dp[i - 1][state + data[i]];
            }
            // dp[i][data[i]] += dp[i]
        }
        dp[i][data[i]]++;

        // for (int state = 0; state <= (i + 1) * 2000; state++) {
        //     dp[i][state] += dp[i - 1][state];
        //     if (dp[i - 1][state] != 0) {
        //         cout << "--state: " << state << ", i: " << i << ", dp[i - 1][state]: " << dp[i - 1][state] << endl;
        //     }
        // }

    }

    int64_t ans = 0;
    // for (int i = 0; i < n; i++) {
        for (int state = 0; state <= 100 * 2000; state++) {
            if (dic[state]) {
                ans += dp[n - 1][state];
                if (dp[n - 1][state] != 0)
                cout << "state: " << state << ",dp[i][state]: " << dp[n - 1][state] << endl;
            }
        }
    // }

    cout << ans << endl;

    // cout << dp[0][1] << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    input.tie(nullptr);
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

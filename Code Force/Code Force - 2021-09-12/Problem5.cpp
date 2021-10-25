// https://codeforces.com/contest/1566/problem/D2
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
int n;
string s;

/*
7
1 2
1 2
3 2
1 1 2 2 3 3
3 3
3 4 4 1 1 1 1 1 2
2 2
1 1 2 1
4 2
50 50 50 50 3 50 50 50
4 2
6 6 6 6 2 2 9 6
2 9
1 3 3 3 3 3 1 1 3 1 3 1 1 3 3 1 1 3

*/

struct P {
	int val;
	int idx;
};

void solve() {
    int n;
	int m;
	cin >> n;
	cin >> m;
	vector<P> data;
    int val;
	for (int i = 0; i < n * m; i++) {
		cin >> val;
		data.push_back({val, i});
	}

	sort(data.begin(), data.end(), [](P p1, P p2) {
		if (p1.val == p2.val) {
			return p1.idx < p2.idx;
		}
		return p1.val < p2.val;
	});

	int64_t ans = 0;

	for (int i = 0; i < n * m; i += m) {
		sort(data.begin() + i, data.begin() + i + m, [](P p1, P p2) {
			return p1.idx <= p2.idx;
		});
		Ordered_set s;
		for (int j = i; j < i + m; j++) {
			s.insert(data[j].val);
			ans += (int64_t) s.order_of_key(data[j].val);
		}
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

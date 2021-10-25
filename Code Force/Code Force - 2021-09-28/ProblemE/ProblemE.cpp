// // build: g++ -o ProblemE ProblemE.cpp -std=c++11 && ProblemE

// #include <iostream>
// #include <vector>
// using namespace std;
// #include <bits/stdc++.h>
// #include <algorithm>
// #include <unordered_map>
// #include <unordered_set>
// #include <set>
// #include <map>
// #include <vector>
// #include <deque>

// // C++ Program to implement the
// // above approach
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
 
// using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type,
//              less_equal<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     Ordered_set;

// // cin, output
// #include <iostream>
// string file_name = "ProblemE.in";
// // ifstream cin;

// void solve() {
//     // code here
//     int n;
//     cin >> n;
//     vector<int> data;
//     int val;
//     for (int i = 0; i < n; i++) {
//         cin >> val;
//         data.push_back(val);
//     }

//     deque<int> d;
//     for(int i = 0; i < n; i++) {
//         if (i == 0) {
//             d.push_back(data[i]);
//             continue;
//         }
//         int f = d.front();
//         if (data[i] < f) {
//             d.push_front(data[i]);
//         } else {
//             d.push_back(data[i]);
//         }
//     }

//     while (!d.empty()) {
//         cout << d.front() << " ";
//         d.pop_front();
//     }
//     cout << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;

//     set<int> a;

//     // cin.open(file_name);

//     cin >> t;
//     while (t--) {
//         solve();
//     }

//     // cin.close();
//     return 0;
// }


// build: g++ -o ProblemE ProblemE.cpp -std=c++11 && ProblemE

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
typedef tree<pair<int, int>, null_type,
             less_equal<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;

#include <iostream>
string file_name = "ProblemE.in";

void solve() {
    // code here
    int n;
    cin >> n;
    vector<int> data;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        data.push_back(val);
    }
    
    Ordered_set s;
    int64_t ans = 0;
    for (int i = 0; i < data.size(); i++) {
        int64_t size = s.size();
        int64_t it = s.order_of_key({data[i], i});
        int64_t it2 = s.order_of_key({data[i] - 1, i});
        int64_t plus = min(it2, size - it);
        ans += plus;
        s.insert({data[i], i});
    }

    cout <<  ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;

    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

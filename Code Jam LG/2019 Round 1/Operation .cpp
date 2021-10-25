// https://codejam.lge.com/problem/17126
// build: 

// 
/*

g++ -o Operation  Operation .cpp -std=c++11 && Operation 


12
1 27 30
1 25 40
3 17
1 17 20
1 5 50
2 10 20
2 25 30
3 25
3 17
1 27 20
2 10 20
2 25 30

*/

#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <set>

#include <iostream>
#include <vector>
using namespace std;

// C++ Program to implement the
// above approach
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 

struct P {
    int index;
    int val;
    bool operator<(const P& p ) const {
        return index < p.index;
    }
    bool operator==(const P& p ) const {
        return index == p.index;
    }
    bool operator<=(const P& p ) const {
        return index <= p.index;
    }
};

// Policy based data structure
typedef tree<P, null_type,
             less_equal<P>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
     {
        int n;
        cin >> n;

        Ordered_set s;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                // add val to index
                int index;
                int val;
                cin >> index;
                cin >> val;
                P p = {index, val};
                auto it = s.order_of_key(p);
                auto real_p = s.find_by_order(it);
                
                 if (real_p->index == index) {
                     // found element
                    //  cout << (*it).val;
                    //  P p1 = (*it);
                    // real_p->val += val;
                     s.erase(real_p);
                     s.insert({index, val + real_p->val});
                 } else {
                     s.insert(p);
                 }
                cout << "-->a1";
                sum += val;
                cout << "sum: " << sum << " " << endl;
                cout << "s --------------" << endl;
                for (auto e : s) {
                    cout << e.val << " ";
                }
                cout << endl;

            } else if (type == 2) {
                // Purge index
                int index1;
                int index2;
                cin >> index1;
                cin >> index2;
                if (index1 > index2) {
                    int tmp = index1;
                    index1 = index2;
                    index2 = tmp;
                }

                P p1 = {index1, 0};
                auto it1 = s.order_of_key(p1);
                // cout << "it1: " << it1 << endl;
                auto real_p1 = s.find_by_order(it1);
                // cout << "real_p1->val: " << real_p1->val << endl;
                if (real_p1->index != index1) {
                    // it1++;
                    real_p1 = s.find_by_order(it1);
                }


                P p2 = {index2, 0};
                auto it2 = s.order_of_key(p2);
                // cout << "it2: " << it2 << endl;
                auto real_p2 = s.find_by_order(it2);
                // cout << "real_p2->val: " << real_p2->val << endl;
                if (real_p2->index != index2) {
                    it2--;
                    if (it2 > s.size() - 1) {
                        it2 = s.size() - 1;
                    }
                    real_p2 = s.find_by_order(it2);
                }

                cout << "get from: " << real_p1->index << " to: " << real_p2->index << endl;

            } else {
                // sum range query from index1, to index2
                int index;
                cin >> index;
                P p = {index, 0};
                auto it = s.order_of_key(p);
                auto real_p = s.find_by_order(it);
                
                if (real_p->index == index) {
                    //  P p1 = (*it);
                     s.erase(real_p);
                     sum -= real_p->val;
                     
                }
                cout << "--->a3" << endl;
                cout << "sum: " << sum << " ";
                cout << "s --------------" << endl;
                for (auto e : s) {
                    cout << e.val << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}


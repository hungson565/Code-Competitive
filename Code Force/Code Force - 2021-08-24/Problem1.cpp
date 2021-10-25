// https://codeforces.com/contest/1561/problem/A
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int T;
int n;

/*

3
3
3 2 1
7
4 5 7 1 3 2 6
5
1 2 3 4 5

*/


void solve() {
    cin >> n;
	
    vector<int> data;
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        data.push_back(val);
    }

    int count = 1;
    while (count <= n) {
        // iterate
        if (count % 2 == 1) {
            // cout << "count1: " << count << endl;
            bool isTrue = true;
            for (int i = 0; i < n - 1; i += 2) {
                if (data[i] > data[i + 1]) {
                    int tmp = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = tmp;
                    isTrue = false;
                }
            }
            // for (auto d : data) {
            //     cout << d << ", ";
            // }
            // cout << endl;
            if (isTrue) {
                // cout << "break, count: " << count << endl;
                break;
            }
            
        } else {
            // cout << "count2: " << count << endl;
            bool isTrue = true;
            for (int i = 1; i < n; i += 2) {
                if (data[i] > data[i + 1]) {
                    int tmp = data[i];
                    data[i] = data[i + 1];
                    data[i + 1] = tmp;
                    isTrue = false;
                }
            }
            // for (auto d : data) {
            //     cout << d << ", ";
            // }
            // cout << endl;
            if (isTrue) {
                break;
            }
        }
        
        count++;
    }

    cout << count - 1 << endl;



}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

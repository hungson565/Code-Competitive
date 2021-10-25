#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int T;

int n;
int k;

struct P {
    int A;
    int B;
};

void solve() {
    cin >> n;
    cin >> k;

    vector<int> A;
    vector<int> B;

    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        A.push_back(val);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        B.push_back(val);
    }

    vector<P> data;
    for (int i = 0; i < n; i++) {
        data.push_back({A[i], B[i]});
    }

    sort(data.begin(), data.end(), [](P d1, P d2) {
        return (d1.A - d1.B) < (d2.A - d2.B);
    });

    int64_t ans = 0;

    int lower = (n - k) / 2;
    if ((n - k) % 2 != 0) {
        lower++;
    }

    int upper = (n + k) / 2;

    int count = 0;
    // for (int i = 0; i < n; i++) {
    //     cout << data[i].A << " " << data[i].B << endl;
    // }
    for (int i = 0; i < n; i++) {
        // cout << "i : " << i << "...";
        if (i < lower) {
            ans += data[i].B;
            // cout << "+ " << data[i].B << endl;
            continue;
        }
        if (i == lower) {
            count = lower;
        }

        if (count == upper) {
            ans += data[i].A;
            // cout << " + " << data[i].A << endl;
        } else {
            // cout << data[i].A << " and" << data[i].B << endl;
            if (data[i].A > data[i].B) {
                ans += data[i].A;
                // cout << " + " << data[i].A << endl;
            } else {
                ans += data[i].B;
                // cout << " + " << data[i].B << endl;
                count++;
            }
        }
    }

    cout<< ans << endl;

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
    return 0;
}

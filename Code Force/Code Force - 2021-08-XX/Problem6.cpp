// https://codeforces.com/contest/1559/problem/A
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

int64_t T;
int64_t N;
int64_t k;

/*
4
1 1
221 2
177890 2
998244353 1

*/

int64_t numDigits(int64_t number)
{
    int64_t digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

int64_t cal(int64_t N, int64_t k) {
    if (N == 0) {
        return 0;
    }
    if (k == 1) {
        int64_t n = numDigits(N);
        if (n == 1) {
            return N;
        }
        int64_t first = N / (pow(10, n - 1));
        int64_t ans = first;
        for (int64_t i = 0; i < n - 1; i++) {
            ans = ans * 10 + first;
        }
        if (ans >= N) {
            return ans;
        }
        first++;
        ans = first;
        for (int64_t i = 0; i < n - 1; i++) {
            ans = ans * 10 + first;
        }
        return ans;
    }

    // k == 2

    int64_t n = numDigits(N);
    if (n == 1) {
        return N;

    }
    int64_t first = N / (pow(10, n - 1));
    int64_t remain = N - first * pow(10, n - 1);
    int64_t count_first = 1;

    // cout << "(remain / (pow(10, numDigits(remain) - 1): " << (int64_t)(remain / (pow(10, numDigits(remain) - 1))) << endl;

    while ((int64_t)(remain / (pow(10, numDigits(remain) - 1))) == first) {
        remain -= first * pow(10, numDigits(remain) - 1);
        count_first++;
        // cout << "count_first++: " << count_first << endl;
    }

    // cout << "remain: " << remain << endl;

    int64_t count_remain = n - count_first;

    int64_t ans_remain = cal(remain, 1);
    // cout << "ans_remain: " << ans_remain << endl;
    int64_t ans = first;
    for (int64_t i = 0; i < count_first - 1; i++) {
        ans = ans * 10 + first;
    }
    for (int64_t i = 0; i < count_remain; i++) {
        ans = ans * 10;
    }
    ans = ans + ans_remain;

    // cout << "ans2: " << ans << endl;

    int64_t last = ans % 10;
    // cout << "last: " << last << ", first: " << first << endl;
    if (last > first) {
        int64_t sub = last - first;
        for (int64_t i = 0; i < count_remain - 2; i++) {
            sub = sub * 10 + (last - first);
        }
        // cout << "sub: " << sub << endl;
        // cout << "sub: " << sub << endl;
        int64_t ans2 = ans - sub;
        // cout << "ans22: " << ans2 << endl;
        // cout << "ans2: " << ans2 << endl;
        if (ans2 >= N) {
            // cout << "ans22acept: " << endl;
            ans = ans2;
        }
    }
    
    return ans;
}


void solve() {
    cin >> N;
    cin >> k;

    int64_t ans = cal(N, k);

    cout  << ans << endl;

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

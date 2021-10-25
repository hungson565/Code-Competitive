#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
bool aliceWin[100000+10];
int cum[100000+10] = {0};
int T, A, k;

void SieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }
 
    for (int p = 2; p <= n; p++) {
        if (prime[p]) primes.push_back(p);
    }
}

int main () {
    SieveOfEratosthenes(100000);
    for (auto& p : primes) {
        aliceWin[p] = true;
        aliceWin[p+1] = true;
    }

    for (int i = 3; i <= 100000; ++i) {
        if (aliceWin[i] == false) {
            int j = 0;
            while (i + primes[j] < 100000) {
                aliceWin[i + primes[j]] = true;
                j++;
            }
        }
    }
    
    // cout << "ok" << endl;
    
    int cur = 0; 
    for (int i = 3; i <= 100000; ++i) {
        if (!aliceWin[i]) cur++;
        cum[i] = cur;
    }

    cin >> T;
    while (T--) {
        cin >> A >> k;
        int count = 0;
        int index = 3;

        for (int i = 3+k-1; i <= A; ++i) {
            if (cum[i] - cum[i-k] > count) {
                count = cum[i] - cum[i-k];
                index = i;
            }
        }

        cout << count << " " << index - k + 1 << endl;
    }
    return 0;
}
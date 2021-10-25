// https://codejam.lge.com/problem/19595

// build: g++ -o PrimeNumberGame PrimeNumberGame.cpp -std=c++11 && PrimeNumberGame

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int T;
int N;

/*


TC:

5
12 2
12 3
12 4
100 11
1000 15

*/

bool isPrime[100005];

void sieve(int N) {
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             // Mark all the multiples of i as composite numbers
             for(int j = i * i; j <= N; j += i)
                 isPrime[j] = false;
        }
    }
}

int main() {
    sieve(100001);

    int count = 0;
    for (int i = 1; i <= 100000; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    vector<int> primes;
    vector<bool> flag(100005, false);
    flag[0] = true;
    flag[1] = true;
    flag[2] = true;
    
    for (int i = 1; i <= 100000; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            flag[i] = true;
            flag[i + 1] = true;
        }
    }

    for (int i = 1; i <= 100000; i++) {
        if (flag[i] == true) {
            continue;
        }
        for (int p = 0; p < primes.size(); p++) {
            if (primes[p] + i > 100000) {
                break;
            }
            flag[i + primes[p]] = true;
        }

    }


    vector<int> prefix(100005, 0);
    prefix[0] = 0;
    prefix[1] = 0;
    prefix[2] = 0;
    for (int i = 1; i <= 100000; i++) {
        if (flag[i] == false) {
            prefix[i] = prefix[i - 1] + 1;
        } else {
            prefix[i] = prefix[i - 1];
        }
    }

    cin >> T;
    while (T > 0) {
        int A;
        int k;
        cin >> A;
        cin >> k;
        // need to find min x; 2 <= x <= A + 1 - k
        // with x, pick N, x ≤ N ≤ x+k-1
        int val = 0;
        int x_max = 1;
        for (int x = 2; x <= A + 1 - k; x++) {
            if (prefix[x + k - 1] - prefix[x - 1] > val) {
                val = prefix[x + k - 1] - prefix[x - 1];
                x_max = x;
            }
        }

        cout << val << " " << x_max << endl;

        T--;
    }
}

/*
Input N, for example: N = 3
Output : 0, 1, 12, 13, 123, 2, 23, 3
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// result container
vector<int> data;

// print data
void printResult() {
    for (int i = 0; i < data.size(); ++i) {
        cout << data[i];
    }
    cout << endl;
}

void subset(int N, int count) {
    
    if (count == N) {
        printResult();
    } else {
        data.push_back(count);
        subset(N, count + 1);
        data.pop_back();
        subset(N, count + 1);
    }
}

int main()
{
    int N;
    cin >> N;
    
    // 1. Backtrack use recursive
    // subset(N, 0);

    // 2. Backtrack use bitsets
    for (int i = 0; i < pow(2, N) - 1; i++) {
        vector<int> data;
        for (int j = 0; j < N; j++) {
            if ((1 << j) & i) {
                data.push_back(j);
            }
        }
        for (auto e : data) {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}

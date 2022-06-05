// https://codejam.lge.com/problem/17430

// build: g++ -o Streetlightposts Streetlightposts.cpp -std=c++11 && Streetlightposts

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int T;
int N, M;

/*

TC:

4
5 0
5 1
5 5
5 10

*/



void solve() {
    // input
	cin >> N;
    cin >> M;
    
    int tich_luy = 0;

    while (M >= N - 1) {
        M -= N - 1;
        N--;
        tich_luy++;
    }

    vector<int> data;
    for (int i = 1; i <= N; i++) {
        data.push_back(i);
    }

    int count = 0;
    int index = 0;
    int bound = N - 1;
    while (count < M) {
        int tmp = data[index];
        data[index] = data[index + 1];
        data[index + 1] = tmp;
        index++;
        if (index == bound) {
            index = 0;
            bound--;
        }
        count++;
    }

    for (int i = 0; i < N; i++) {
        data[i] += tich_luy;
    }

    for (int i = tich_luy; i >= 1; i--) {
        data.push_back(i);
    }

    for (int i = 0; i < data.size(); i++) {
        printf("%d ", data[i]);
    }
    cout << endl;
    
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

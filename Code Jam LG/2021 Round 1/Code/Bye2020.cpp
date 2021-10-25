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
int n;

/*

3
4
101010 101010 101011 101011
5
100000 100000 100000 101011 101011
4
202021 0 1 202020

*/

vector<int> meannings = {202021, 20202021, 202002021, 202012021, 202022021, 202032021, 202042021, 202052021, 202062021, 202072021, 202082021, 202092021};

void solve() {
	const int MODULE = 10000;
    cin >> n;

    vector<int> data;
	int d;
    for (int i = 0; i < n; ++i) {
    	scanf("%d", &d);
    	data.push_back(d);
	}
	
	sort(data.begin(), data.end());
	
	int64_t count = 0;
	
    for (int i = 0; i < n - 1; i++) {
		int num1 = data[i];
		for (auto sum : meannings) {
			int num2 = sum - num1;
			count += upper_bound(data.begin() + i + 1, data.end(), num2) - lower_bound(data.begin() + i + 1, data.end(), num2);
		}
		
	}
	
	cout << count << endl;
}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

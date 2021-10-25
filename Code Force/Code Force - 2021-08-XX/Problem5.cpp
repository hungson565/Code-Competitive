// https://codeforces.com/contest/1559/problem/A
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

int T;
string s;

/*
7
abacabaaacaac
nowyouknowthat
polycarppoycarppoyarppyarppyrpprppp
isi
everywherevrywhrvryhrvrhrvhv
haaha
qweqeewew

*/


void solve() {
    cin >> s;
    int n = s.size();

    unordered_map<char, int> m;

    for (auto c : s) {
        m[c]++;
    }

    // for (auto e : m) {
    //     cout << e.first << ", " << e.second << endl;
    // }

    unordered_set<char> se;
    // character from end to begin
    vector<char> v;
    // number of character apear in t
    vector<int> num_of_c(200, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (!se.count(s[i])) {
            se.insert(s[i]);
            v.push_back(s[i]);
            int divide = (m.size() + 1 - v.size());
            if (m[s[i]] % divide != 0) {
                cout << "-1" << endl;
                return;
            }
            num_of_c[s[i]] = m[s[i]] / divide;
        }
    }

//    cout << "---" << endl;
//    for (auto e : v) {
//        cout << e << " " << num_of_c[e] << endl;
//    }
    
    // reverse v
    reverse(v.begin(), v.end());
    
//    for (auto e : v) {
//    	cout << e << " ";
//	}
//	cout << endl;
    
    // contruct t:
    int num_of_c_t = 0;
    for (auto e : v) {
        num_of_c_t += num_of_c[e];
    }
    
    string t = s.substr(0, num_of_c_t);
//    cout << "t: " << t << endl;
    
    
    // check if t satify
    
    string s2 = t;
    string tmp = t;
    for (int i = 0; i < v.size(); i++) {
    	string t2 = "";
    	for (auto c : tmp) {
    		if (c != v[i]) {
    			t2 += c;
			}
		}
		s2 += t2;
		tmp = t2;
	}
	
//	cout << "s2: " << s2 << endl;
	
	if (s2 == s) {
		cout << t << " ";
		for (auto c : v) {
			cout << c;
		}
		cout << endl;
	} else {
		cout << "-1" << endl;
	}

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
}

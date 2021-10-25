// https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A1
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;
#include <fstream>

int T;
int a, b;

/*

6
ABC
F
BANANA
FBHC
FOXEN
CONSISTENCY

*/

ifstream infile;
ofstream outfile;

void solve(int number) {
    
    string s;

    infile >> s;

    int consonant = 0;
    int un_consonant = 0;
    int consonant_max = 0;
    char consonant_max_c = 0;
    int un_consonant_max = 0;
    char un_consonant_max_c = 0;

    vector<int> m(26, 0);

    for (auto c : s) {
        m[c - 'A']++;
        if (c == 'A' || c == 'E' || c == 'O' || c == 'I' || c == 'U') {
            consonant++;
        } else {
            un_consonant++;
        }
    }

    for (int i = 0; i < 26; i++) {
        char c = i + 'A';
        if (c == 'A' || c == 'E' || c == 'O' || c == 'I' || c == 'U') {
            if (consonant_max < m[i]) {
                consonant_max = m[i];
                consonant_max_c = c;
            }
        } else {
            if (un_consonant_max < m[i]) {
                un_consonant_max = m[i];
                un_consonant_max_c = c;
            }
        }
    }

    // base on consonent;
    int ans1 = 0;
    if (consonant == 0) {
        // consonant_max_c = 'A';
        ans1 = un_consonant;
    } else {
        ans1 = (consonant - consonant_max) * 2 + un_consonant;
    }

    // base on un_consonent
    int ans2 = 0;
    if (un_consonant == 0) {
        ans2 = consonant;
    } else {
        ans2 = (un_consonant - un_consonant_max) * 2 + consonant;
    }

    int ans = min(ans1, ans2);

    cout  << "Case #" << number << ": " << ans << endl;
    outfile << "Case #" << number << ": " << ans << endl;
    

}

int main() {
    infile.open("consistency_chapter_1_input.txt");
    outfile.open("output.txt");
    
    infile >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }
    infile.close();
    outfile.close();
}

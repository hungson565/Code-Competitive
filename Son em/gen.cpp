#include <bits/stdc++.h>
using namespace std;
long long rnd(long long a, long long b){
    return a + rand() % (b - a + 1);
}

int main() {
	srand(1);
    long T = 1000;
    cout<<T<<endl;
    string s = "0123456789ABCDEF";
    for(int t= 0; t <T; ++t) {
		long n = rnd(1, 15);
		//cout << n << endl;
		string test = "";
		for(int i = 0; i < n; ++i) {
			long a = rnd(0, 15);
			test += s[a];
		}
		cout << test << endl;
	}
	
}

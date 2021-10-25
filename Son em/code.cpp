#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
#define endl '\n'
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#ifdef _LOCAL_
#define debug(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif
unordered_map<char, int> hashMap;
bool valid(string a, string b) {
	debug(a, b);
	int n = a.length();
	int m = b.length();
	int i = 0, j = 0;
	while(i < n && a[i] == '0')
		i++;
	while(j < m && b[j] == '0')
		j++;
	a = a.substr(i);
	b = b.substr(j);
	n = a.length();
	m = b.length();
	//debug(a, b);
	if(n > m)
		return true;
	if(m > n)
		return false;
	for(i = 0; i < n; ++i) 
	{
		if(hashMap[a[i]] < hashMap[b[i]])
			return false;
	}
	return true;
}

void solve() {
	string s;
	cin >> s;
	int n = s.length();	
	int cnt = 0;
	vector<int> ans;
	int top = (1 << (n - 1));
	for(int i = 0; i < top; ++i) {
		string cur = s.substr(0, 1);
		string prev = "0";
		//debug(i); 
		bool ok = true;
		for(int j = 1; j < n; ++j) {
			if((1<<(j - 1)) & i) {
				cur += s[j];
			} 
			else {
				if(valid(cur, prev)) {
					prev = cur;
					cur = s.substr(j, 1);
				}
				else {
					ok = false;
					break;
				}
			}
		}
		if(!valid(cur, prev))
			ok = false;
		if(ok)  {
			ans.push_back(i);
			++cnt;
		}
	}
	
    cout << cnt << endl;
	for(int x : ans)
		debug(x);
}


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s = "0123456789ABCDEF";
	int cur = 0;
	for(char& c : s) {
		hashMap[c] = cur++;
	}
	int t;
    cin >> t;
    while(t--) solve();
    //string a = "1";
    //string b = "02";
    //cout << valid(a, b) << endl;
	return 0;
}

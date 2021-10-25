// https://vnoi.info/problems/list_solutions/BAOVE/


// Dinic: https://vnoi.info/problems/show_solution/BAOVE/1386601/



#include <bits/stdc++.h>
using namespace std;


#include <unordered_map>

#define pii pair<int, int>
#define F first
#define S second
const int INF = 1e9;

using namespace std;

// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

struct MaxFlow {
    vector< vector< int> > adj;
    vector< int> par;
    // vector< vector< int> > cap;
    // vector< vector< int> > flow;

    unordered_map<pair<int, int>, int, hash_pair> cap;
    unordered_map<pair<int, int>, int, hash_pair> flow;

    int n;
    MaxFlow(int _n) {
        n = _n;
        adj.resize(n + 1);
        for (int i = 0; i < adj.size(); i++) {
            adj[i].resize(3);
        }
        // cap.resize(n + 1, vector< int>(n + 1));
        // flow.resize(n + 1, vector< int>(n + 1));
        par.resize(n + 1);
    }
    void addEdge(int u, int v, int c) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        // cap[u][v] += c;
        cap[{u, v}] += c;
    }
    int bfs(int source, int sink) {
        queue< pii> q;
        q.push({source, INF});
        fill(par.begin(), par.end(), -1);
        par[source] = -2;
        while(!q.empty()) {
            int cur = q.front().F;
            int f = q.front().S;
            q.pop();
            for(int& nxt : adj[cur]) {
                // if(par[nxt] == -1 && cap[cur][nxt] - flow[cur][nxt] > 0) {
                if(par[nxt] == -1 && cap[{cur, nxt}] - flow[{cur, nxt}] > 0) {
                    par[nxt] = cur;
                    // int new_f = min(f, cap[cur][nxt] - flow[cur][nxt]);
                    int new_f = min(f, cap[{cur, nxt}] - flow[{cur, nxt}]);
                    if(nxt == sink)
                        return new_f;
                    q.push({nxt, new_f});
                }
            }
        }
        return 0;
    }
    int findMaxFlow(int source, int sink) {
        int totalFlow = 0;
        int f = 0;
        while((f = bfs(source, sink))) {
            totalFlow += f;
            int cur = sink;
            while(cur != source) {
                int prv = par[cur];
                // flow[prv][cur] += f;
                // flow[cur][prv] -= f;
                flow[{prv, cur}] += f;
                flow[{cur, prv}] -= f;

                cur = prv;
            }
        }
        return totalFlow;
    }
};


int main() {
    int n;
    cin >> n;
    int u, v, c;
    MaxFlow mf(n);
    while(cin >> u >> v >> c) {
        mf.addEdge(u, v, c);
    }
    cout << mf.findMaxFlow(n, 1);
    return 0;
}

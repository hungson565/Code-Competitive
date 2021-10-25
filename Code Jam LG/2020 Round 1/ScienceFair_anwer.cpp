#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define pii pair<int, int>
#define F first
#define S second
const int INF = 1e9;

using namespace std;

// g++ -o ScienceFair ScienceFair.cpp -std=c++11

/*

3
3
1 1 1
1 1
1 1
2 2 3
4
1 1 1
1 1
1 1
2 2 3
5
1 1 2
1 1
1 5
4 1 2 3 5

*/

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

    unordered_map<pair<int, int>, int, hash_pair> cap;
    unordered_map<pair<int, int>, int, hash_pair> flow;

    int n;
    MaxFlow(int _n) {
        n = _n;
        adj.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            adj[i].resize(3);
        }
        par.resize(n + 1);
    }
    void addEdge(int u, int v, int c) {
        adj[u].push_back(v);
        adj[v].push_back(u);
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
                if(par[nxt] == -1 && cap[{cur, nxt}] - flow[{cur, nxt}] > 0) {
                    par[nxt] = cur;
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
                flow[{prv, cur}] += f;
                flow[{cur, prv}] -= f;

                cur = prv;
            }
        }
        return totalFlow;
    }
};

int T;

void solve() {

    int n;
    int na, nb, nc;
    int number;
    int val;

    // 1. intput && 2. add edge

    scanf("%d", &n);
    
    scanf("%d%d%d", &na, &nb, &nc);

    unordered_set<int> sa;
    unordered_set<int> sb;
    unordered_set<int> sc;

    scanf("%d", &number);
    for (int i = 0; i < number; i++) {
        scanf("%d", &val);
        sa.insert(val);
    }

    scanf("%d", &number);
    for (int i = 0; i < number; i++) {
        scanf("%d", &val);
        sb.insert(val);
    }

    scanf("%d", &number);
    for (int i = 0; i < number; i++) {
        scanf("%d", &val);
        sc.insert(val);
    }

    unordered_set<int> gA;
    unordered_set<int> gB;
    unordered_set<int> gC;
    unordered_set<int> gAB;
    unordered_set<int> gBC;
    unordered_set<int> gCA;
    unordered_set<int> gABC;

    for (int i = 1; i <= n; i++) {
        int count_a = sa.count(i);
        int count_b = sb.count(i);
        int count_c = sc.count(i);

        if (count_a + count_b + count_c == 3) {
            gABC.insert(i);
        } else if (count_a + count_b == 2) {
            gAB.insert(i);
        } else if (count_b + count_c == 2) {
            gBC.insert(i);
        } else if (count_a + count_c == 2) {
            gCA.insert(i);
        } else if (count_a == 1) {
            gA.insert(i);
        } else if (count_b == 1) {
            gB.insert(i);
        } else if (count_c == 1) {
            gC.insert(i);
        }
    }

    MaxFlow mf(12);
    // 1: group A: group of A
    // 2: group B: group of B
    // 3: group C: group of C
    // 4: group AB: group of AB
    // 5: group BC: group of BC
    // 6: group CA: group of CA
    // 7: group ABC: group of ABC
    // 8: A
    // 9: B
    // 10: C
    // 11: source
    // 12: sink
    int source = 11;
    int sink = 12;

    // connect source to 1,2,3...7
    mf.addEdge(source, 1, gA.size());
    mf.addEdge(source, 2, gB.size());
    mf.addEdge(source, 3, gC.size());
    mf.addEdge(source, 4, gAB.size());
    mf.addEdge(source, 5, gBC.size());
    mf.addEdge(source, 6, gCA.size());
    mf.addEdge(source, 7, gABC.size());


    // connect 1,2,3...7 to A, B, C
    mf.addEdge(1, 8, gA.size());
    mf.addEdge(2, 9, gB.size());
    mf.addEdge(3, 10, gC.size());
    mf.addEdge(4, 8, gAB.size());
    mf.addEdge(4, 9, gAB.size());
    mf.addEdge(5, 9, gBC.size());
    mf.addEdge(5, 10, gBC.size());
    mf.addEdge(6, 10, gCA.size());
    mf.addEdge(6, 8, gCA.size());
    mf.addEdge(7, 8, gABC.size());
    mf.addEdge(7, 9, gABC.size());
    mf.addEdge(7, 10, gABC.size());

    // connect A, B, C to sink
    mf.addEdge(8, sink, na);
    mf.addEdge(9, sink, nb);
    mf.addEdge(10, sink, nc);

    // 3. output
    printf("%d\n", mf.findMaxFlow(source, sink));

    // Output flow
    for (int i = 0; i < mf.flow[{1, 8}]; i++) {
        printf("%d A\n", *(gA.begin()));
        gA.erase(gA.begin());
    }

    for (int i = 0; i < mf.flow[{2, 9}]; i++) {
        printf("%d B\n", *(gB.begin()));
        gB.erase(gB.begin());
    }

    for (int i = 0; i < mf.flow[{3, 10}]; i++) {
        printf("%d C\n", *(gC.begin()));
        gC.erase(gC.begin());
    }

    for (int i = 0; i < mf.flow[{4, 8}]; i++) {
        printf("%d A\n", *(gAB.begin()));
        gAB.erase(gAB.begin());
    }

    for (int i = 0; i < mf.flow[{4, 9}]; i++) {
        printf("%d B\n", *(gAB.begin()));
        gAB.erase(gAB.begin());
    }

    for (int i = 0; i < mf.flow[{5, 9}]; i++) {
        printf("%d B\n", *(gBC.begin()));
        gBC.erase(gBC.begin());
    }

    for (int i = 0; i < mf.flow[{5, 10}]; i++) {
        printf("%d C\n", *(gBC.begin()));
        gBC.erase(gBC.begin());
    }

    for (int i = 0; i < mf.flow[{6, 10}]; i++) {
        printf("%d C\n", *(gCA.begin()));
        gCA.erase(gCA.begin());
    }

    for (int i = 0; i < mf.flow[{6, 8}]; i++) {
        printf("%d A\n", *(gCA.begin()));
        gCA.erase(gCA.begin());
    }

    for (int i = 0; i < mf.flow[{7, 8}]; i++) {
        printf("%d A\n", *(gABC.begin()));
        gABC.erase(gABC.begin());
    }

    for (int i = 0; i < mf.flow[{7, 9}]; i++) {
        printf("%d B\n", *(gABC.begin()));
        gABC.erase(gABC.begin());
    }

    for (int i = 0; i < mf.flow[{7, 10}]; i++) {
        printf("%d C\n", *(gABC.begin()));
        gABC.erase(gABC.begin());
    }

}

int main() {
    cin >> T;
    while (T > 0) {
        solve();
        T--;
    }
    return 0;
}

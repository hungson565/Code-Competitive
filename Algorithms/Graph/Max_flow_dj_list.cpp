//https://cp-algorithms.com/graph/edmonds_karp.html

#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;

int n;
vector<vector<int>> capacity(100);
vector<vector<int>> adj(100);

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    // v: 0,1,2,3,4,5
    // int idx = 0;
    // adj[0] = {1, 4};
    // adj[1] = {2, 3};
    // adj[2] = {5};
    // adj[3] = {5};
    // adj[4] = {1, 3};
    // adj[5] = {};

    // capacity[0] = {7, 4};
    // capacity[1] = {5, 3};
    // capacity[2] = {8};
    // capacity[3] = {5};
    // capacity[4] = {3, 2};
    // capacity[5] = {};

    // cout << maxflow(0, 5) << endl;

	return 0;
}

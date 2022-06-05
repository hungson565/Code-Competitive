struct DSU {
    vector<int> pair;
    DSU(int n) {
        pair.resize(n);
    }
    int get(int u) {
        return pair[u];
    }
    void set(int u, int v) {
        pair[u] = v;
        pair[v] = u;
    }
};


int solve(vector<int>& a) {
    int n = a.size();
    DSU dsu(n + 1);
    int ans = 0;
    for(int i = 0; i < n; i += 2) {
        dsu.set(a[i], a[i+1]);
    }
    for(int i = 0; i < n; i += 2) {
        int j = i + 1;
        int pi = dsu.get(i);
        int pj = dsu.get(j);
        if(pi != j) {
            ++ans;
            dsu.set(i, j);
            dsu.set(pi, pj);
        }
    }
    return ans;
}

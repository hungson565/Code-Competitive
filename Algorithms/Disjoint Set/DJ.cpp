class DJ {
public:
    #define M 50000
    DJ(int N) : N(N) {
        init();
    }    
    int parent[M], rank[M];
    int count[M];

    void init() {
        for (int i=0; i<N; i++) {
            parent[i] = i;
            rank[i] = 0;
            count[i] = 1;
        }
    }

    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (rank[u] == rank[v]) rank[u]++;
        if (rank[u] < rank[v]) {
            parent[u] = v;
            count[v] += count[u];
        }
        else {
            parent[v] = u;
            count[u] += count[v];
        }
    }
    
    int getCount(int i) {
      int parent = find(i);
      return count[parent];
    }
private:
    int N;
};
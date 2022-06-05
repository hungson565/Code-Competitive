// https://binarysearch.com/room/Synchronized-Swimming-fGOYKA7J9T?questionsetIndex=2

#define N 100000

int parent[N];
int rankk[N];
int maxx[N];
int minn[N];

void init() {
    for (int i=0; i<N; i++) {
        parent[i] = i;
        rankk[i] = 0;
        maxx[i] = INT_MIN;
        minn[i] = INT_MAX;
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
    if (rankk[u] == rankk[v]) rankk[u]++;
    if (rankk[u] < rankk[v]) parent[u] = v;
    else parent[v] = u;
}

// class way

class DJ {
public:
    DJ(int N) : N(N) {
        init();
    }    
    int parent[M], rank[M];
    int count[M];

    void init() {
        for (int i=0; i<N; i++) {
            parent[i] = i;
            rank[i] = 0;
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
        return count[i];
    }
private:
    int N;
};

int solve(vector<vector<int>>& data) {
    int ans = 0;
    int n = data.size();
    if (n == 0) {
        return 0;
    }
    sort(data.begin(), data.end(), [](vector<int>& v1, vector<int>& v2) {
        if (v1[0] < v2[0]) {
            return true;
        }
        if (v1[0] == v2[0] && v1[1] < v2[1]) {
            return true;
        }
        return false;
    });
    init();
    // join
    int f = find(0);
    maxx[f] = max(maxx[f], data[0][1]);
    minn[f] = min(minn[f], data[0][0]);
    for (int i = 1; i < n; i++) {
        int f0 = find(i - 1);

        if (maxx[f0] >= data[i][0] - 1) {
            join(i - 1, i);
        }
        int f = find(i);
        maxx[f] = max(maxx[f], data[i][1]);
        minn[f] = min(minn[f], data[i][0]);
    }

    vector<bool> check(n, false);
    for (int i = 0; i < n; i++) {
        int f = find(i);
        if (check[f] == true) {
            continue;
        }
        ans += maxx[f] - minn[f] + 1;
        check[f] = true;
    }

    return ans;
}


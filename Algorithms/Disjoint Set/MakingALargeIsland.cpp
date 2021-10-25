// https://leetcode.com/explore/featured/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3835/

class Solution {
public:
    
    #define N 600
    
    pair<int, int> parent[N][N];
    int rank[N][N];
    int count[N][N];

    void init() {
        for (int i=0; i<N; i++) {
            for (int j = 0; j < N; j++) {
                parent[i][j] = {i, j};
                rank[i][j] = 0;
                count[i][j] = 1;
            }   
        }
    }

    pair<int, int> find(pair<int, int> p) {
        int u = p.first;
        int v = p.second;
        if (parent[u][v] != p) parent[u][v] = find(parent[u][v]);
        return parent[u][v];
    }

    void join(pair<int, int> p1, pair<int, int> p2) {
        p1 = find(p1);
        p2 = find(p2);
        if (p1 == p2) return;
        if (rank[p1.first][p1.second] == rank[p2.first][p2.second]) rank[p1.first][p1.second]++;
        if (rank[p1.first][p1.second] < rank[p2.first][p2.second]) {
            parent[p1.first][p1.second] = p2;
            count[p2.first][p2.second] += count[p1.first][p1.second];
        }
        else {
            parent[p2.first][p2.second] = p1;
            count[p1.first][p1.second] += count[p2.first][p2.second];
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        init();
        int n = grid.size();
        
        bool no_0 = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    no_0 = false;
                }
            }
        }
        if (no_0) {
            return n * n;
        }
        
        vector<vector<bool>> flag(n, vector<bool>(n, false));
        
        // Push all 1 to queue, bfs to join all sets
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && flag[i][j] == false) {
                    q.push({i, j});
                    flag[i][j] = true;
                    // BFS to make sets
                    while (!q.empty()) {
                        auto e = q.front(); q.pop();
                        vector<int> offset = {-1, 0, 1, 0, -1};
                        for (int i = 0; i < 4; i++) {
                            int nx = e.first + offset[i];
                            int ny = e.second + offset[i + 1];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1 && flag[nx][ny] == false) {
                                // join
                                join({nx, ny}, {e.first, e.second});
                                q.push({nx, ny});
                                flag[nx][ny] = true;
                            }
                        }
                    }
                    
                }
            }
        }

        // Check all 0 that it could connect max
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    continue;
                }
                int val = 1;
                vector<int> offset = {-1, 0, 1, 0, -1};
                set<pair<int, int>> s;
                for (int k = 0; k < 4; k++) {
                    int nx = i + offset[k];
                    int ny = j + offset[k + 1];
                    
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        // sum neighbor
                        auto p = find({nx, ny});
                        if (!s.count(p)) {
                            val += count[p.first][p.second];
                            s.insert(p);
                        }
                        
                    }
                }
                ans = max(ans, val);
            }
        }
        
        
        return ans;
    }
};


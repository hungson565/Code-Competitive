// https://binarysearch.com/room/Badge-first-search-xGhOS3syZq?questionsetIndex=2

// bimask

int calMask(int mask, const vector<int>& data, vector<int>& dp) {
    if (dp[mask] != 1000) {
        return dp[mask];
    }

    int n = data.size();

    int ans = __builtin_popcount(mask) - 1;
    for (int pick = 1; pick < (mask); pick++) {
        if ((mask - pick) == (mask ^ pick)) {
            // check sum = 0;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (pick & (1 << i)) {
                    sum += data[i];
                } 
            }
            if (sum != 0) continue;
            ans = min(ans, (__builtin_popcount(pick) - 1) + calMask(mask - pick, data, dp));
        }
    }

    dp[mask] = ans;
    return ans;
}

int solve(vector<vector<int>>& trans) {
    unordered_map<int, int> m;
    for (auto e : trans) {
        m[e[0]] += e[2];
        m[e[1]] -= e[2];
    }

    int n = m.size();
    vector<int> data;
    for (auto e : m) {
        data.push_back(e.second);
    }

    vector<int> dp(1 << n, 1000); // mask
    return calMask((1 << n) - 1, data, dp);
}
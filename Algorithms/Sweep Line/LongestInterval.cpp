struct P {
    int t;
    bool open;
};

int solve(vector<vector<int>>& arr) {
    vector<P> data;
    for (const auto& e : arr) {
        data.push_back({e[0], true});
        data.push_back({e[1], false});
    }

    // sort all points for LINE SWEEP process
    sort(data.begin(), data.end(), [](const P& p1, const P& p2) {
        if (p1.t < p2.t) {
            return true;
        }
        if (p1.t == p2.t && p1.open == true && p2.open == false) {
            return true;
        }
        return false;
    });

    stack<int> s;
    int ans = 0;
    for (const auto& e : data) {
        // if open, then push to stack
        // if close, then cal interval
        if (e.open) {
            s.push(e.t);
        } else {
            int start = s.top();
            s.pop();
            ans = max(ans, e.t - start + 1);
        }
    }

    return ans;
}
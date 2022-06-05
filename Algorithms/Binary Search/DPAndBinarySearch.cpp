// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3950/

class Solution {
public:
    struct T {
        int s;
        int e;
        int profit;
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<T> data;
        for (int i = 0; i < n; i++) {
            data.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(data.begin(), data.end(), [](const T& t1, const T& t2) {
            return t1.s < t2.s || (t1.s == t2.s && t1.e < t2.e);
        });
        
        vector<int> dp(n + 5, 0);
        dp[n - 1] = data[n - 1].profit;
        vector<int> m(n + 5, 0);
        m[n - 1] = dp[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            // cal dp[i] from dp[i + 1]
            int find = data[i].e;
            T search = {find, 0, 0};
            auto it = lower_bound(data.begin() + i + 1, data.end(), search, [](T t1, T t2) {
               return t1.s < t2.s;
            }) - data.begin();

            // it--;
            if (it >= n) {
                // not found
                // 1. available
                if (data[i].e <= data[i + 1].s && data[it - 1].s > find) {
                    dp[i] = dp[i + 1] + data[i].profit;
                } else {
                    dp[i] = data[i].profit;
                }
            }
            dp[i] = m[it] + data[i].profit;
            m[i] = max(m[i + 1], dp[i]);
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};



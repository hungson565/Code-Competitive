// https://leetcode.com/submissions/detail/558014537/

class Solution {
public:
    
    int64_t cal(int i, bool alice, vector<int>& stoneValue, vector<vector<int64_t>>& dp) {
        int n = stoneValue.size();
        if (i >= n) {
            return 0;
        }
        
        if (dp[i][(int)alice] != -1000) {
            return dp[i][(int)alice];
        }
        
        int64_t final_ans = 0;
        
        if (alice) {
            int64_t ans = INT_MIN;
            ans = max(ans, stoneValue[i] + cal(i + 1, !alice, stoneValue, dp));
            if (i + 1 <= n - 1) {
                ans = max(ans, stoneValue[i] + stoneValue[i + 1] + cal(i + 2, !alice, stoneValue, dp));
            }
            if (i + 2 <= n - 1) {
                ans = max(ans, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] + cal(i + 3, !alice, stoneValue, dp));
            }
            final_ans = ans;
        } else {
            int64_t ans = INT_MAX;
            ans = min(ans, cal(i + 1, !alice, stoneValue, dp));
            if (i + 1 <= n - 1) {
                ans = min(ans, cal(i + 2, !alice, stoneValue, dp));
            }
            if (i + 2 <= n - 1) {
                ans = min(ans, cal(i + 3, !alice, stoneValue, dp));
            }
            final_ans = ans;
        }
        
        dp[i][(int)alice] = final_ans;
        return dp[i][(int)alice];
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int64_t>> dp(n + 1, vector<int64_t>(2, -1000));
        int64_t point = cal(0, true, stoneValue, dp);
        int64_t sum = std::accumulate(stoneValue.begin(), stoneValue.end(), 0);

        if (point * 2 > sum) {
            return "Alice";
        } else if (point * 2 == sum) {
            return "Tie";
        }
        return "Bob";
    }
};

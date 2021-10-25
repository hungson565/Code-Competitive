// https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/


class Solution {
public:
    
    int cal(int i, int mask, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        int n = nums1.size();
        if (dp[i][mask] != -1) {
            return dp[i][mask];
        }
        
        if (i == n) {
            return 0;
        }
        
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                continue;
            }
            ans = min(ans, (nums1[i] ^ nums2[j]) + cal(i + 1, mask | (1 << j), nums1, nums2, dp));
        }
        
        return  dp[i][mask] = ans;
    }
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        vector<vector<int>> dp(n + 5, vector<int>((1<<n) - 1 + 5, -1));
        int mask = 0;
        return cal(0, mask, nums1, nums2, dp);
    }
    
};

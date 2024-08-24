class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        for(auto it: nums) {
            s += it;            
        }
        if(s % 2 != 0) return false;

        int t = s / 2;
        vector<vector<int>> dp(n + 1, vector<int> (t + 1, 0));
        for(int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= t; ++j) {
                if(j >= nums[i-1]) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][t];
    }
};

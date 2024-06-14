class Solution {
public:
    int f(int n, vector<int> &dp) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        long long mini = LLONG_MAX;
        
        for (int i = 1; i * i <= n; ++i) {
            long long res = 1 + f(n - i * i, dp);
            mini = min(res, mini);
        }

        return dp[n] = (int)mini;
    }
    
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        int ans = f(n, dp);
        return ans;
    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            dp[i] = matrix[n - 1][i];
        }
        for (int i = n - 2; i >= 0; --i) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; ++j) {
                temp[j] = matrix[i][j] + min(dp[j], min(j > 0 ? dp[j - 1] : INT_MAX, j < n - 1 ? dp[j + 1] : INT_MAX));
            }
            dp = temp; 
        }

        int mini = INT_MAX; 
        for (int i = 0; i < n; ++i) {
            mini = min(mini, dp[i]);
        }

        return mini;
    }
};
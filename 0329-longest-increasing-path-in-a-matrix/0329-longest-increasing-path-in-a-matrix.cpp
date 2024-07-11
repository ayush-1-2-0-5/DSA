class Solution {
public:
    vector<vector<int>> dp;
    int n, m;
    int delrow[4] = {1, 0, -1, 0};
    int delcol[4] = {0, -1, 0, 1};

    int solve(vector<vector<int>>& matrix, int r, int c, int prev) {
        if (r < 0 || r >= n || c < 0 || c >= m || matrix[r][c] <= prev) return 0;
        
        if (dp[r][c] != -1) return dp[r][c];
        
        int a = 0;
        for (int i = 0; i < 4; ++i) {
            a = max(a, solve(matrix, r + delrow[i], c + delcol[i], matrix[r][c]));
        }
        
        return dp[r][c] = 1 + a;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        
        n = matrix.size();
        m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, solve(matrix, i, j, -1));
            }
        }

        return ans;
    }
};

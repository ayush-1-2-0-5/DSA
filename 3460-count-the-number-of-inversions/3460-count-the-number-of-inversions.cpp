class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
         const int mod = 1e9 + 7;
        vector<vector<long long>> dp(301, vector<long long>(405, 0));
        dp[0][0] = 1;
        vector<int> req(301, -1);

        for (auto it : requirements) {
            req[it[0]] = it[1];
        }

        int last = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= last + 1; ++j) {
                for (int k = 0; k <= i; ++k) {
                    if (j + k < 405) {
                        if (req[i] != -1 && req[i] != (j + k)) {
                            continue;
                        }
                        dp[i][j + k] =(dp[i][j+k] +dp[i - 1][j])%mod;
                        if (dp[i][j + k] > 0) {
                            last = max(last, j + k);
                        }
                    }
                }
            }
        }

        long long result = 0;
        for (int j = 0; j < 405; ++j) {
            result = (result+dp[n-1][j])%mod;
        }
        
        return static_cast<int>(result);
    }
};

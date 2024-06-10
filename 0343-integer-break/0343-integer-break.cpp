class Solution {
public:
  int integerBreak(int n) {
    const int MAX_N = 58;
    vector<int> dp(MAX_N + 1, 0);

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    for (int i = 4; i <= n && i <= MAX_N; ++i) {
      for (int j = 1; j < i; ++j) {
        dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
      }
    }

    return dp[n];
  }
};

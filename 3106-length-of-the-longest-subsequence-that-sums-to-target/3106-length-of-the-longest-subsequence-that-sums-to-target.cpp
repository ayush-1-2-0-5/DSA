class Solution {
 public:
  int lengthOfLongestSubsequence(vector<int>& nums, int target) {
    const int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    for (int i = 0; i <= n; ++i)
      dp[i][0] = 0;

    for (int i = 1; i <= n; ++i) {
      const int num = nums[i - 1];
      for (int j = 1; j <= target; ++j)
        if (j < num || dp[i - 1][j - num] == -1)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = max(dp[i - 1][j], 1 + dp[i - 1][j - num]);
    }

    return dp[n][target];
  }
};

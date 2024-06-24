class Solution {
public:
    long long solve(vector<vector<long long>>& dp, vector<int>& nums, int idx, int f) {
        if (idx < 0)
            return 0;
        if (idx == 0) {
            if (!f)
                return nums[0];
            else
                return LLONG_MIN;
        }

        if (dp[idx][f] != -1)
            return dp[idx][f];

          __int128_t ans = LLONG_MIN;

        if (f == 0) {
            ans = max(ans, (__int128_t)nums[idx] + solve(dp, nums, idx - 1, 0));
            ans = max(ans, (__int128_t)nums[idx] +solve(dp, nums, idx - 1, 1));
        } else {
              __int128_t negated_value = -(  __int128_t)nums[idx];
            ans = max(ans, negated_value + solve(dp, nums, idx - 1, 0));
        }

        return dp[idx][f] = ans;
    }

    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return max(solve(dp, nums, n - 1, 0), solve(dp, nums, n - 1, 1));
    }
};

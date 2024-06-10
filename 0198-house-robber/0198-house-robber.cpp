class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind < 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        int include = nums[ind] + f(ind - 2, nums, dp);
        int exclude = f(ind - 1, nums, dp);

        return dp[ind] = max(include, exclude);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int a = f(n - 2, nums, dp1); 
        int b = f(n - 1, nums, dp2);  

        return max(a,b);
    }
};
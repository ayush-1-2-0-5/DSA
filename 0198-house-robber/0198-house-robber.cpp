class Solution {
public:
    int solve(int n,vector<int> &arr,vector<int>&dp)
    {
        dp[0]=arr[0];
        for(int i=1;i<n;++i)
        {
            int p=arr[i];

            if(i>1)
            p+=dp[i-2];

            int notp=dp[i-1];

            dp[i]=max(p,notp);

        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        return solve(nums.size(),nums,dp);
    }
};
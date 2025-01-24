class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(auto it:nums)
        {
            s+=it;
        }


        if(s%2)
        return false;


        int t=s/2;
        int n=nums.size();

        vector<vector<bool>> dp(n+1,vector<bool>(t+1,false));


        for(int i=0;i<n;++i)
        {
          dp[i][0]=true;
        }

        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=t;++j)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }

        return dp[n][t];
    }
};
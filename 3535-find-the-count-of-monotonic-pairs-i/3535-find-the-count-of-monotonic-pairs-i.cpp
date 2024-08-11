class Solution {
public:
   int mod=1e9+7;
    int countOfPairs(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(53,0));


        for(int c=0;c<=nums[0];++c) dp[0][c]=1;

        for(int idx=1;idx<n;++idx)
        {
            for(int j=0;j<=nums[idx];++j)
            {
                int w=0;
                for(int prev=0;prev<=50;++prev)
                {
                           //forarr1             //for arr2
                       if(  prev<=j     && (nums[idx]-j<=nums[idx-1]-prev))
                       {
                        w=(w%mod+dp[idx-1][prev]%mod)%mod;
                       }
                }
                dp[idx][j]=w;
            }
        }

        int ans=0;
        for(int i=0;i<=50;++i )
        ans=(ans%mod+dp[n-1][i]%mod)%mod;

        return ans;
    }
};
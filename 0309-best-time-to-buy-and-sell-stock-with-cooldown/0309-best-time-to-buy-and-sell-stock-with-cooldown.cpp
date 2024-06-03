class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));

        for(int i=n-1;i>=0;--i)
        {
            for(int j=0;j<2;++j)
            {
                if(j)//can buy
                {
                  dp[i][j]=max(dp[i+1][j],-prices[i]+dp[i+1][0]);

                }
                else//can sell
                {
                    dp[i][j]=max(dp[i+1][j],prices[i]+dp[i+2][1]);
                }
            }
        }
        return dp[0][1];
    }
};
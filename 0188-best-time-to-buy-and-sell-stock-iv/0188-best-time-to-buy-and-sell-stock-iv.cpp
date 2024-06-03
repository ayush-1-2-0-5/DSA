class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        for(int i=n-1;i>=0;--i)
        {
            for(int j=0;j<2;++j)
            {
                for(int cap=1;cap<k+1;++cap)
                {
                    if(j==0)//can buy
                    {
                    dp[i][j][cap]=max(-prices[i]+dp[i+1][1][cap],dp[i+1][0][cap]);

                    }

                   else if(j)//can sell
                    {
                        dp[i][j][cap]=max(prices[i]+dp[i+1][0][cap-1],dp[i+1][1][cap]);

                    }
                    
             }
            }
        }
        return dp[0][0][k];
    }
};
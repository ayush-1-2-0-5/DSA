class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
          int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        for(int idx=n-1;idx>=0;--idx)
        {
            for(int buy=0;buy<2;++buy)
            {
                for(int cap=1;cap<=k;++cap)
                {
                    if(buy)
                     {
                         dp[idx][buy][cap]=max(dp[idx+1][0][cap-1]+prices[idx],dp[idx+1][1][cap]);
                     }
                     else
                     {
                        dp[idx][buy][cap]=max(dp[idx+1][1][cap]-prices[idx],dp[idx+1][0][cap]);
                     }
                }
            }
        }
        return dp[0][0][k];
    }
};
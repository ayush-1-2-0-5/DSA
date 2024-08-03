class Solution {
public:

   int solve(vector<int> &dp,int n)
   {
    if(n<=1)
    return 1;
    int ans=0;
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i<=n;++i)
    {
        ans+=solve(dp,i-1)*solve(dp,n-i);
    }
    return dp[n]=ans;
   }


    int numTrees(int n) {
          vector<int> dp(21,-1);
          return solve(dp,n);
    }
};
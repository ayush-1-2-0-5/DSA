class Solution {
public:
    int f(vector<int> &cuts,int i,int j, vector<vector<int>> &dp)  //here i and j are indexes
    {
        if(i>j)
        return 0;
      if( dp[i][j]!=-1) return dp[i][j];
      int mini=INT_MAX;
        for(int k=i;k<=j;++k)
        {
            mini=min(mini,cuts[j+1]-cuts[i-1]+f(cuts,i,k-1,dp)+f(cuts,k+1,j,dp));
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());
        int m=cuts.size();

        vector<vector<int>> dp(m,vector<int>(m,-1));
           
           return f(cuts,1,m-2,dp);

    }
};
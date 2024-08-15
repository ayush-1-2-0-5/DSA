class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> dp(n,-1);

        for(int i=0;i<n;++i)
        {
            dp[i]=matrix[n-1][i];
        }

        for(int i=n-2;i>=0;--i)
        {
            vector<int> temp=dp;
            for(int j=0;j<n;++j)
            {

                dp[j]=min(j==0?INT_MAX:temp[j-1],min(temp[j],j==n-1?INT_MAX:temp[j+1]))+matrix[i][j];
            }
        }


        int mini=INT_MAX;
        for(auto it: dp)
        {
            mini=min(it,mini);
        }
   return mini;
    }
};
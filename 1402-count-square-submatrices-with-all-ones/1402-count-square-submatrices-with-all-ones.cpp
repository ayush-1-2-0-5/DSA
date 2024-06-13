class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<n;++i)
        {
            dp[0][i]=matrix[0][i];

        }
        for(int j=1;j<m;++j)
        {
            dp[j][0]=matrix[j][0];
        }

        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(matrix[i][j]==0)
                dp[i][j]=0;

                else
                {
                    int a=dp[i-1][j-1];
                    int b=dp[i-1][j];
                    int c=dp[i][j-1];

                    dp[i][j]=1+min(a,min(b,c));
                }
            }
        }

        int ans=0;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                ans+=dp[i][j];
            }
        }

        return ans;
    }
};
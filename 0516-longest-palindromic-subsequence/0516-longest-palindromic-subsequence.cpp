class Solution {
public:

  int lcs(string temp,string s)
  {
     int n=s.length();

     vector<vector<int>> dp(n+1,vector<int> (n+1,0));
     int maxi=0;
     for(int i=1;i<=n;++i)
     {
        for(int j=1;j<=n;++j)
        {
            if(temp[i-1]==s[j-1])
            dp[i][j]=1+dp[i-1][j-1];

            else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
     }

    return dp[n][n];
  }


    int longestPalindromeSubseq(string s) {
        int ans=0;
        string temp=s;
        reverse(temp.begin(),temp.end());

        ans=lcs(temp,s);

        return ans;
    }
};
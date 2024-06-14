class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n=o.size();
        int m=o[0].size();
         vector<vector<int>> nw(n,vector<int>(m,-1));
          nw[0][0]=1;
         for(int i=0;i<n;++i)
         {
             for(int j=0;j<m;++j)
             {
                  if(o[i][j]==1)
                  {
                    nw[i][j]=0;
                  }
             }
         }

         for(int i=0;i<m;++i)
         {
             if(nw[0][i]==0)
             {
                  for(int j=i;j<m;++j)
                  {
                     nw[0][j]=0;

                  }  
                  break;      
             }

             else
             nw[0][i]=1;
          }

            for(int i=0;i<n;++i)
         {
             if(nw[i][0]==0)
             {
                  for(int j=i;j<n;++j)
                  {
                     nw[j][0]=0;
                     
                  } 
                  break;       
             }
             else 
             nw[i][0]=1;
          }

          for(int i=1;i<n;++i)
          {
              for(int j=1;j<m;++j)
              {
                  if(nw[i][j]!=0)
                  nw[i][j]=nw[i-1][j]+nw[i][j-1];
              }
          }
        return nw[n-1][m-1];
    }
};
class Solution {
public:
    vector<vector<int>> ctpre(char ch,vector<vector<char>> grid)
    {
          int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> res(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(ch==grid[i][j])
                res[i][j]=1;
            }
        }
         for(int i=0;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                 res[i][j]+=res[i][j-1];
            }
        }


         for(int i=1;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
               res[i][j]+=res[i-1][j];
            }
        }
        return res;
        
 }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> preX=ctpre('X',grid);

        vector<vector<int>> preY=ctpre('Y',grid);
       int totalct=0;
        for(int i=0;i<n;++i)
        {
           for(int j=0;j<m;++j)
           {
            if(preX[i][j]>0 &&preX[i][j]==preY[i][j])
            totalct++;
           }
        }

        return totalct;
    }
};
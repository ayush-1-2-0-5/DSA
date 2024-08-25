class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        int n=grid.size();
        int m=grid[0].size();
       vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if((i==0||i==n-1||j==0||j==m-1 )&&grid[i][j]==1)
                {
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int delrow[]={1,0,-1,0};
        int delcol[]={0,1,0,-1};

        while(!q.empty())
        {
            auto it= q.front();
            int r=it.first;
            int col=it.second;

            q.pop();
            for(int i=0;i<4;++i)
            {
                int nr=delrow[i]+r;
                int nc=delcol[i]+col;
                if(nr>=0 &&nr<n &&nc>=0 &&nc<m)
                {
                    if(!visited[nr][nc]&& grid[nr][nc]==1)
                    {
                        visited[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }


        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j){
                if(grid[i][j]==1 && visited[i][j]==0)
                ans++;
            }
            
        }
        return ans;
       
    }
};
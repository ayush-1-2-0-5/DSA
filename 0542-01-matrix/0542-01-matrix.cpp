class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    vector<vector<int>> ans(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>> q;
	    
	    for(int i=0;i<n;++i)
	    {
	        for(int j=0;j<m;++j)
	         {
	             if(grid[i][j]==0)
	             {
	                 vis[i][j]=1;
	                 q.push({{i,j},0});
	                 
	             }
	             else 
	             vis[i][j]=0;
	         }
	    }
	    
	    while(!q.empty())
	    {
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int step=q.front().second;
	        q.pop();
	        int delrow[]={0,-1,0,1};
	        int delcol[]={1,0,-1,0};
	        
	        for(int i=0;i<4;++i)
	        {
	                int nrow=row+delrow[i];
	                int ncol=col+delcol[i];
	                
	                if(nrow>=0 &&nrow<n &&ncol>=0 &&ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol])
	                {
	                    q.push({{nrow,ncol},step+1});
	                    vis[nrow][ncol]=1;
	                    ans[nrow][ncol]=step+1;
	                }
	        }
	    }
	    
	  return ans;  
	}
    
};
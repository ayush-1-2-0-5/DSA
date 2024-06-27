class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
     vector<vector<int>> ans=image;
     int initialcolor=image[sr][sc];
      if (initialcolor == color) {
            return image;  
        }
     
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
         int delrow[]={0,-1,0,1};
         int delcol[]={1,0,-1,0};        
         queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty())
        {
           int r=q.front().first;
           int c=q.front().second;
           q.pop();
           ans[r][c]=color;
           visited[r][c]=true;
           for(int i=0;i<4;++i)
           {
               int nr=r+delrow[i];
               int nc=c+delcol[i];

               if(nr>=0 && nr<n &&nc>=0 &&nc<m &&!visited[nr][nc]&&image[nr][nc]==initialcolor)
               {
                   q.push({nr,nc});
               }
           }           
       }
       return ans;
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> v(n,vector<int> (m,INT_MAX));
        v[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        int dist=INT_MAX;;

        while(!pq.empty())
        {
            int dis=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            if(r==n-1 &&c==m-1)
            dist=min(dist,dis);

            int delr[]={0,1,0,-1};
            int delc[]={1,0,-1,0};

            for(int i=0;i<4;++i)
            {
                int nr=r+delr[i];
                int nc=c+delc[i];

                if(nr>=0 &&nr<n && nc>=0 && nc<m)
                {
                    int d=abs(heights[nr][nc]-heights[r][c]);

                    if(max(d,v[r][c])<v[nr][nc])
                    {
                    v[nr][nc]=max(d,v[r][c]);
                    pq.push({v[nr][nc],{nr,nc}});
                    }

                }
            }
        }
        return dist;
    }
};
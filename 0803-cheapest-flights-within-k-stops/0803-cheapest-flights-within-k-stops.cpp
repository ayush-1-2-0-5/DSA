class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>> adj[n];
        for(auto it:flights)

        {
                adj[it[0]].push_back({it[1],it[2]});

        }
           priority_queue<pair<int,pair<int,int>> ,vector<pair<int ,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        vector<int> v(n,INT_MAX);
        v[src]=0;

           pq.push({0,{src,0}});
int ans=INT_MAX;
           while(!pq.empty())
           {
               int stops=pq.top().first;
               int node=pq.top().second.first;
               int cst=pq.top().second.second;
               pq.pop();

               if (node == dst) {
                ans = min(ans, cst);
                continue;
            }
 
 for(auto it:adj[node])
 {
     int nd=it.first;
     int cost=it.second;

     if(cst+cost<v[nd] && stops<=k)
     {
         v[nd]=cst+cost;
         pq.push({stops+1,{nd,v[nd]}});
     }

 }                
   

           }

           if(ans==INT_MAX)
           return -1;

           else return ans;
        

    }
};
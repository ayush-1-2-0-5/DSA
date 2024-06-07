class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
            vector<int> revadj[V];
       vector<int> indeg(V,0);
       
       for(int i=0;i<V;++i)
       {
           for(auto it: adj[i])
           {
               revadj[it].push_back(i);
               indeg[i]++;
           }
       }
       
       vector<int>ans;
       queue<int> q;
       for(int i=0;i<V;++i)
       {
           if(indeg[i]==0)
           {
               q.push(i);
           }
       }
       
       while(!q.empty())
       {
           int a=q.front();
           
           q.pop();
           ans.push_back(a);
           
           for(auto it: revadj[a])
           {
               if(indeg[it]!=0)
               {
                   indeg[it]--;
               }
               if(indeg[it]==0)
               q.push(it);
           }
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
    
};
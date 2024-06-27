class Solution {
public:


    void dfs(unordered_map<string,vector<pair<string,double>>> adj,string src,string dest, unordered_set<string> &visited, double &ans,double prod){

       if(visited.find(src)!=visited.end())
       {
           return ;
       }
       visited.insert(src);

       if(src==dest)
       {
           ans=prod;
           return;
       }

      for (auto& ad : adj[src]) {
        string u = ad.first;
        double val = ad.second;
        dfs(adj, u, dest, visited, ans, prod * val);
         }


    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> answer;
      int n=equations.size();

      unordered_map<string,vector<pair<string,double>>> adj;

      for(int i=0;i<n;++i)
      {
         string u=equations[i][0];
         string v=equations[i][1];

         double value=values[i];

         adj[u].push_back({v,value});
         adj[v].push_back({u,1.0/value});
      }


      for(auto query: queries)
      {
          string src=query[0];
          string dest=query[1];


           double ans=-1;
           double prod=1.0;
           
        if(adj.find(src)!=adj.end())
        {
            unordered_set<string> visited;
            dfs(adj,src,dest,visited,ans,prod);
        }

answer.push_back(ans);

      }
    return answer;
    }
};
class Solution {
    private: 
    vector<int> tree[100007];
    int ans=0;
    int dfs(int src,int par)
    {
        int src_size=1;
        unordered_set<int> usize;
        for(auto c:tree[src])
        {
            if(c!=par)
            {
              int curr_size=dfs(c,src);
              src_size+=curr_size;
              usize.insert(curr_size);
            }
        }
           if(usize.size()<=1)ans++;
          return src_size;

    }

public:
    int countGoodNodes(vector<vector<int>>& edges) {
        for(auto it:edges)
        {
            tree[it[0]].push_back(it[1]);
            tree[it[1]].push_back(it[0]);
        }
        int x=dfs(0,-1);
return ans;
    
    }
};
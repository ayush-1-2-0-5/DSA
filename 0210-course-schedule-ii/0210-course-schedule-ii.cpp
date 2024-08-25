class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n,0);

        vector<int> adj[n];

        for(auto it: pre)
        {
            adj[it[1]].push_back(it[0]);
        }


        for(int i=0;i<n;++i)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;

        for(int i=0;i<n;++i)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty())
        {
            int a=q.front();
            ans.push_back(a);
            q.pop();

            for(auto it:adj[a])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        if(ans.size()==n)
        return ans;
        else return {};
    }
};
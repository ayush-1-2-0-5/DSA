class Solution {
public:
    void dfs(vector<int> &visited, vector<vector<int>> &adjlist, int node) {
        visited[node] = 1;

        for(auto i : adjlist[node]) {
            if(visited[i] == 0) {
                dfs(visited, adjlist, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjlist(n);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i != j && isConnected[i][j]) { 
                    adjlist[i].push_back(j);  
                }
            }
        }

        vector<int> visited(n, 0);
        int ct = 0;

        for(int i = 0; i < n; ++i) {
            if(visited[i] == 0) {
                ct++;
                dfs(visited, adjlist, i);
            }
        }

        return ct;
    }
};

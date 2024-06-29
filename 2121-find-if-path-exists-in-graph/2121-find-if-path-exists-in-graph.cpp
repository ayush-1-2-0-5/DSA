class Solution {
public:
    bool dfs(vector<int>& visited, vector<int> adj[], int node, int dest) {
        if (node == dest)
            return true;

        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (dfs(visited, adj, it, dest)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adjlist[n];
        for (auto it : edges) {
            adjlist[it[0]].push_back(it[1]);
            adjlist[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0);
        return dfs(visited, adjlist, source, destination);
    }
};

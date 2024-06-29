class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adjList(n);
        
        if (n ==1) return {0};
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].insert(v);
            adjList[v].insert(u);
        }
        
        vector<int> leaves;

        for (int i = 0 ;i < n; ++i) {
            if (adjList[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        while (n > 2) {
            vector<int> newLeaves;
            n -= leaves.size();

            for (int leaf : leaves) {
                int neighbor = *adjList[leaf].begin();
                adjList[neighbor].erase(leaf);
                if (adjList[neighbor].size() == 1) {
                    newLeaves.push_back(neighbor);
                }
            }
            leaves = newLeaves;
        }

        return leaves;
    }
};
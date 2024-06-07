class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        dist[k] = 0;
        queue<pair<int,int>> q;
        q.push({k, 0});

        while (!q.empty()) {
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();

            for (auto& edge : adj[node]) {
                int neighbor = edge.first;
                int disToNeighbor = edge.second;
                if (dist[neighbor] > dis + disToNeighbor) {
                    dist[neighbor] = dis + disToNeighbor;
                    q.push({neighbor, dist[neighbor]});
                }
            }
        }

        int ans = -1;
        for (int i = 1; i < n + 1; ++i) {
            if (dist[i] == INT_MAX) {
                return -1;
            } else {
                ans = max(ans, dist[i]);
            }
        }

        return ans;
    }
};

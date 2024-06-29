#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(vector<pair<int, int>> adj[], int node, int n) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[node] = 0;
        pq.push({0, node});
        
        while (!pq.empty()) {
            int currNode = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();
            
            for (auto it : adj[currNode]) {
                int nextNode = it.first;
                int weight = it.second;
                if (currDist != INT_MAX && currDist + weight < dist[nextNode]) {
                    dist[nextNode] = currDist + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        
        return dist;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<int> from0;
        vector<int> fromN;
        int size = edges.size();
        vector<pair<int, int>> adj[n];

        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        from0 = dijkstra(adj, 0, n);
        fromN = dijkstra(adj, n - 1, n);

        int shortestdist = from0[n - 1];

        vector<bool> ans(size, false);

        for (int i = 0; i < size; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            if ((from0[u] != INT_MAX && fromN[v] != INT_MAX && from0[u] + wt + fromN[v] == shortestdist) ||
                (from0[v] != INT_MAX && fromN[u] != INT_MAX && from0[v] + wt + fromN[u] == shortestdist)) {
                ans[i] = true;
            }
        }

        return ans;
    }
};

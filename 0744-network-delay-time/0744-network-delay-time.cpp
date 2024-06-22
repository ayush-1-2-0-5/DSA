#include <vector>
#include <climits>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0; 

        for (int i = 0; i < n - 1; ++i) {
            for (const auto& edge : times) {
                int u = edge[0] - 1;
                int v = edge[1] - 1;
                int weight = edge[2];
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        int maxDelay = 0;
        for (int d : dist) {
            if (d == INT_MAX) {
                return -1; 
            }
            maxDelay = max(maxDelay, d);
        }

        return maxDelay;
    }
};

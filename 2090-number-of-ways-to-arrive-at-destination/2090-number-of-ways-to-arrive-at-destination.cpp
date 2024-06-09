
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        const int mod = 1e9 + 7;
        dist[0] = 0;
        ways[0] = 1;
        vector<pair<int, int>> adj[n];

        for (auto& road : roads) {
            adj[road[0]].emplace_back(road[1], road[2]);
            adj[road[1]].emplace_back(road[0], road[2]);
        }

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue;

            for (auto& neighbor : adj[node]) {
                int nd = neighbor.first;
                long long d = neighbor.second;

                if (dist[nd] > dis + d) {
                    dist[nd] = dis + d;
                    ways[nd] = ways[node];
                    pq.push({dist[nd], nd});
                } else if (dist[nd] == dis + d) {
                    ways[nd] = (ways[nd] + ways[node]) % mod;
                }
            }
        }

        return static_cast<int>(ways[n - 1] % mod);
    }
};


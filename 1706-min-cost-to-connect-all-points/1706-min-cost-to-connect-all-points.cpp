class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) { 
        int n = points.size();
        if (n == 1)
            return 0;

        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);
        minDist[0] = 0;

        auto manhattanDistance = [&](int i, int j) {
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); 

        int result = 0;
        int edgesUsed = 0;

        while (edgesUsed < n) {
            auto [currentDist, u] = pq.top();
            pq.pop();

            if (inMST[u])
                continue;

            inMST[u] = true;
            result += currentDist;
            edgesUsed++;

            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    int dist = manhattanDistance(u, v);
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                        pq.push({dist, v});
                    }
                }
            }
        }

        return result;
    }
};
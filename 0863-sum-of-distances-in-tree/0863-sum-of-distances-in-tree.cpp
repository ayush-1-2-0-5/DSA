class Solution {
public:
    int N;
    vector<int> ans, count;
    vector<vector<int>> graph;

    void dfs(int node, int par) {
        for (auto child : graph[node]) {
            if (child != par) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }

    void dfs2(int node, int par) {
        for (auto child : graph[node]) {
            if (child != par) {
                ans[child] = ans[node] - count[child] + (N - count[child]);
                dfs2(child, node);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        graph = vector<vector<int>>(n);

        for (auto it : edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        ans = vector<int>(n, 0);
        count = vector<int>(n, 1);
        
        dfs(0, -1);
        dfs2(0, -1);
        
        return ans;
    }
};

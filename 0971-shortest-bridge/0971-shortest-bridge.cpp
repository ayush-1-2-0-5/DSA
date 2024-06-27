class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, queue<pair<int, int>>& q, int r, int c, int n) {
        if (r < 0 || r >= n || c < 0 || c >= n || visited[r][c] == 1 || grid[r][c] == 0)
            return;

        visited[r][c] = 1;
        q.push({r, c});

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [dr, dc] : directions) {
            dfs(grid, visited, q, r + dr, c + dc, n);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        bool found = false;

        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, visited, q, i, j, n);
                    found = true;
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                        if (grid[nr][nc] == 1) {
                            return steps;
                        }
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

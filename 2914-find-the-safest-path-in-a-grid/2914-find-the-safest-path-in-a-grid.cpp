class Solution {
public:
    bool isSafe(vector<vector<int>>& matrix, int dist) {
        int n = matrix.size();
        queue<pair<int, int>> q;

        if (matrix[0][0] < dist)
            return false;
        q.push({0, 0});
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        visited[0][0] = true;

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (r == n-1 && c == n-1)
                return true;
            int delrow[] = {1, 0, -1, 0};
            int delcol[] = {0, -1, 0, 1};
            for (int i = 0; i < 4; ++i) {
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || matrix[nr][nc] < dist)
                    continue;

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        int len = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                dist[r][c] = len;

                int delrow[] = {1, 0, -1, 0};
                int delcol[] = {0, -1, 0, 1};

                for (int i = 0; i < 4; ++i) {
                    int nr = r + delrow[i];
                    int nc = c + delcol[i];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc])
                        continue;

                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
            len++;
        }

        int lo = 0;
        int hi = 2 * (n - 1);
        int ans = 0;

        while (hi >= lo) {
            int mid = lo + (hi - lo) / 2;
            if (isSafe(dist, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};

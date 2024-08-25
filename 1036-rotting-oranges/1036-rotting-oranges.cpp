class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q; 
        queue<int> time; 

        int vis[10][10] = {0}; 

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    time.push(0);
                    vis[i][j] = 2;
                }
            }
        }

        int tm = 0;

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            int t = time.front();
            cout<<t<<endl;
            tm = max(t, tm);

            q.pop();
            time.pop();

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, -1, 0, 1};

            for (int i = 0; i < 4; ++i) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 2;
                    q.push({nrow, ncol});
                    time.push(t + 1);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (vis[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return tm;
    }
};
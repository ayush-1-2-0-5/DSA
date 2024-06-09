class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1)
            return -1;

        vector<vector<int>> tempgrid(n, vector<int>(n, INT_MAX));

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        while (!q.empty()) {
            int r = q.front().second.first;
            int c = q.front().second.second;
            int dis = q.front().first;
            q.pop();

            if (r == n - 1 && c == n - 1)
                return dis;

            int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
            int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

            for (int i = 0; i < 8; ++i) {
                int newrow = r + dx[i];
                int newcol = c + dy[i]; 

                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < n) {
                    if (grid[newrow][newcol] == 0 && dis + 1 < tempgrid[newrow][newcol]) {
                        tempgrid[newrow][newcol] = dis + 1;
                        q.push({dis + 1, {newrow, newcol}});
                    }
                }
            }
        }

        return -1;
    }
};
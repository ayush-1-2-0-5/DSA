class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O') {
                    q.push({i, j});
                    board[i][j] = 'T';
                }
            }
        }

        int delRow[] = {0, -1, 0, 1};
        int delCol[] = {1, 0, -1, 0};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O') {
                    q.push({nr, nc});
                    board[nr][nc] = 'T';
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

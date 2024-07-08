

class Solution {
public:
 bool isSafe(int row, int col, vector<string> &board, int n) {
    
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int j = col; j >= 0; j--) {
            if (board[row][j] == 'Q') return false;
        }
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int col, vector<string> &board, int &ans, int n) {
        if (col == n) {
            ans++;
        }

        for (int row = 0; row < n; ++row) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }


    int totalNQueens(int n) {
        int ans=0;
         vector<string> board(n, string(n, '.'));

        solve(0, board, ans, n);
        return ans;
    }
};
class Solution {
public:
    void f(int i, int j, vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& vis, bool &flag) {
        int n = a.size();
        int m = a[0].size();
        vis[i][j] = 1;
        if(a[i][j]==0)flag=false;
        int dir[5] = {0, -1, 0, 1, 0};

        for (int k = 0; k < 4; k++) {
            int nrow = i + dir[k];
            int ncol = j + dir[k + 1];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                if (b[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                    if (a[nrow][ncol] == 0) {
                        flag = false; // This means that the island in `b` is not fully contained within `a`
                    }
                    f(nrow, ncol, a, b, vis, flag);
                }
            }
        }
    }

    int countSubIslands(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && b[i][j] == 1) {
                    bool flag = true;
                    f(i, j, a, b, vis, flag);
                    if (flag) {
                        cout<<i<<" "<<j<<endl;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};

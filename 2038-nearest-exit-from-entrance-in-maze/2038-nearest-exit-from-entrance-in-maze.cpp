#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> temp(n, vector<int>(m, -1));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(maze[i][j] == '+')
                    temp[i][j] = 0;
            }
        }

        int sr = entrance[0];
        int sc = entrance[1];
        queue<pair<pair<int,int>,int>> q;
        q.push({{sr, sc}, 0});
        temp[sr][sc] = 1; 
        int ans = INT_MAX;

        while(!q.empty()) {
            int cr = q.front().first.first;
            int cc = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            int delrow[] = {1, 0, -1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++) {
                int nr = cr + delrow[i];
                int nc = cc + delcol[i];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m) {
                    if(cr != sr || cc != sc) { 
                        ans = min(ans, dist + 1);
                    }
                    continue;
                }
                if(maze[nr][nc] == '.' && temp[nr][nc] == -1) {
                    q.push({{nr, nc}, dist + 1});
                    temp[nr][nc] = 1;  
                }
            }
        }

        return ans == INT_MAX ? -1 : ans-1;
    }
};

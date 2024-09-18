#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define fr(a,b) for(int i = a; i < b; i++)
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vvi visited(n, vi(m, -1)); // Using -1 to track maximum health at each cell

        int delrow[] = {0, 1, 0, -1}; // Directions: right, down, left, up
        int delcol[] = {1, 0, -1, 0};

        // Initial health after considering the starting position
        health -= grid[0][0]; 
        if (health < 1) return false; // Can't start if health drops below 1

        queue<pair<ll, pair<int, int>>> q; // (remaining health, (row, col))
        q.push({health, {0, 0}});
        visited[0][0] = health; // Store health at the start position

        while (!q.empty()) {
            ll currentHealth = q.front().first;
            auto pos = q.front().second;
            q.pop();

            int r = pos.first;
            int c = pos.second;

            // If we reach the bottom-right corner with health > 0
            if (r == n - 1 && c == m - 1 && currentHealth >= 1) {
                return true;
            }

            // Explore all four possible directions
            fr(0, 4) {
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newHealth = currentHealth - grid[nr][nc];
                    if (newHealth > 0) {
                        
                        if (newHealth > visited[nr][nc]) {
                            visited[nr][nc] = newHealth; 
                            q.push({newHealth, {nr, nc}});
                        }
                    }
                }
            }
        }
        return false;
    }
};

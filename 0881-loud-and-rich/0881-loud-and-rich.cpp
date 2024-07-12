#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adjList(n);
        
        for (const auto& pair : richer) {
            adjList[pair[1]].push_back(pair[0]);
        }
        
        vector<int> soln(n, -1);
        
        for (int i = 0; i < n; ++i) {
            if (soln[i] == -1) {
                soln[i] = dfs(i, quiet, adjList, soln);
            }
        }
        
        return soln;
    }
    
private:
    int dfs(int root, vector<int>& quiet, vector<vector<int>>& adjList, vector<int>& soln) {
        if (soln[root] != -1) {
            return soln[root];
        }
        
        int minPos = root;
        int min = quiet[root];
        for (int neighbor : adjList[root]) {
            int ind = dfs(neighbor, quiet, adjList, soln);
            if (quiet[ind] < min) {
                min = quiet[ind];
                minPos = ind;
            }
        }
        
        return soln[root] = minPos;
    }
};

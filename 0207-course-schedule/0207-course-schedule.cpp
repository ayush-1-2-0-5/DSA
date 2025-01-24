class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        
        // Build adjacency list
        for(auto it: pre) {
            adj[it[1]].push_back(it[0]);
        }
        
        // Calculate in-degrees of each course
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; ++i) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            cnt++;

            for(auto next: adj[curr]) {
                indegree[next]--;
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return cnt == numCourses;
    
    }
};
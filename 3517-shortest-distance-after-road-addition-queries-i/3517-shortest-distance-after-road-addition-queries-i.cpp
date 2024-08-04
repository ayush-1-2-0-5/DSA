

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvp vector<vector<pair<int, int>>>
#define fr(a,b) for(int i = a; i < b; i++)
#define frn(a,b) for(int i = a; i >= b; i--)
#define frr(a,b,c) for(int i = a; i <= b &&c; i++)
#define frrn(a,b,c) for(int i = a; i >=b &&c; i--)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;



class Solution {
public:
     int helper(vvp &graph,int n)
     {
         vector<int> dist(n, numeric_limits<int>::max());
        queue<pair<int, int>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            int d = pq.front().first;
            int u = pq.front().second;
            pq.pop();
            if (d > dist[u]) continue;
            for (auto& itr : graph[u]) {
                int v = itr.first;
                int weight = itr.second;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist[n - 1];
    }
     
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
          vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < n - 1; ++i) {
            graph[i].pb({i + 1, 1});
        }
        vector<int> ans;
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            graph[u].pb({v, 1});
            ans.pb(helper(graph, n));
        }
        
        return ans;
    }
};
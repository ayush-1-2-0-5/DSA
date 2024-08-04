#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define fr(a,b) for(int i = a; i < b; i++)
#define frn(a,b) for(int i = a; i >= b; i--)
#define frr(a,b,c) for(int i = a; i <= b && c; i++)
#define frrn(a,b,c) for(int i = a; i >= b && c; i--)
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
    void dfs1(int src, int par, vvi &dp, vvi &adj) {
        int curr;
        for(auto it : adj[src]) {
            if(it == par) continue;

            dfs1(it, src, dp, adj);
            curr = dp[it][0] + (it % 2 ? 1 : 2);

            if(curr > dp[src][0]) {
                dp[src][1] = dp[src][0];
                dp[src][0] = curr;
            } else if(curr > dp[src][1]) {
                dp[src][1] = curr;
            }
        }
    }

    void finaldfs(int src, int par, int parval, vi &ans, vvi &dp, vvi &adj) {
        ans[src] = max(dp[src][0], parval);
        int pa = (src % 2 ? 1 : 2);

        for(auto it : adj[src]) {
            if(it != par) {
                int curr = dp[it][0] + (it % 2 ? 1 : 2);
                int x = (curr == dp[src][0]) ? dp[src][1] : dp[src][0];
                finaldfs(it, src, max(pa + parval, pa + x), ans, dp, adj);
            }
        }
    }

    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vvi adjlist(n);
        for(auto &edge : edges) {
            int nd1 = edge[0];
            int nd2 = edge[1];
            adjlist[nd1].pb(nd2);
            adjlist[nd2].pb(nd1);
        }

        vi ans(n, 0);
        vvi dp(n, vi(2, 0));

        dfs1(0, -1, dp, adjlist);
        finaldfs(0, -1, 0, ans, dp, adjlist);

        return ans;
    }
};

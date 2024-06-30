class Solution {
public:
    class DisjointSet {
        vector<int> rank, uparent;

    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            uparent.resize(n + 1);
            for (int i = 0; i <= n; ++i) {
                uparent[i] = i;
            }
        }

        int findPar(int node) {
            if (uparent[node] == node)
                return node;
            else
                return uparent[node] = findPar(uparent[node]);
        }

        bool UnionbyRank(int u, int v) {
            int up_u = findPar(u);
            int up_v = findPar(v);

            if (up_u == up_v)
                return true;

            if (rank[up_u] > rank[up_v]) {
                uparent[up_v] = up_u;
            } else if (rank[up_v] > rank[up_u]) {
                uparent[up_u] = up_v;
            } else {
                uparent[up_v] = up_u;
                rank[up_u]++;
            }

            return false;
        }
    };

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.rbegin(), edges.rend());

        DisjointSet alice(n);
        DisjointSet bob(n);

        int ans = 0;
        int aliceedges = 0, bobedges = 0;

        for (const auto& edge : edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            if (type == 3) {
                bool aliceUnion = alice.UnionbyRank(u, v);
                bool bobUnion = bob.UnionbyRank(u, v);
                if (aliceUnion && bobUnion) {
                    ans++;
                } else {
                    if (!aliceUnion) aliceedges++;
                    if (!bobUnion) bobedges++;
                }
            } else if (type == 1) {
                if (alice.UnionbyRank(u, v)) {
                    ans++;
                } else {
                    aliceedges++;
                }
            } else if (type == 2) {
                if (bob.UnionbyRank(u, v)) {
                    ans++;
                } else {
                    bobedges++;
                }
            }
        }

        if (aliceedges != n - 1 || bobedges != n - 1) {
            return -1;
        }

        return ans;
    }
};

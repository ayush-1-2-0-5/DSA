#include <vector>
using namespace std;

class Disjoint
{
public:
    vector<int> p, r;

    Disjoint(int n)
    {
        p.resize(n);
        for (int i = 0; i < n; ++i)
        {
            p[i] = i;
        }
        r.resize(n, 1);
    }

    int findpar(int node)
    {
        if (node == p[node])
            return node;
        else
            return p[node] = findpar(p[node]);
    }

    void unionb(int u, int v)
    {
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);

        if (ulp_u == ulp_v)
            return;

        if (r[ulp_u] < r[ulp_v])
        {
            p[ulp_u] = ulp_v;
        }
        else if (r[ulp_v] < r[ulp_u])
        {
            p[ulp_v] = ulp_u;
        }
        else
        {
            p[ulp_v] = ulp_u;
            r[ulp_u]++;
        }
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int edges = connections.size();
        if (n > edges + 1)
            return -1;

        Disjoint ds(n);
        for (auto i : connections)
        {
            int a = i[0];
            int b = i[1];
            ds.unionb(a, b);
        }

        int components = 0;
        for (int i = 0; i < n; ++i)
        {
            if (ds.findpar(i) == i)
                components++;
        }

        return components - 1;
    }
};

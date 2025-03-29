#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    int n, l;
    vector<int> tin, tout;
    vector<vector<int>> up;
    int timer;

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Tree hai, toh bidirectional edges honge
    }

    void dfs(int v, int p)
    {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i - 1]][i - 1];

        for (int u : adjList[v])
        {
            if (u != p)
                dfs(u, v);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = l; i >= 0; --i)
        {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

    void preprocess(int root)
    {
        n = adjList.size();
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<int>(l + 1));
        dfs(root, root);
    }
};

int main()
{
    Graph g;

    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 7}};

    for (auto [u, v] : edges)
    {
        g.addEdge(u, v);
    }

    int root = 0;
    g.preprocess(root);

    cout << "LCA of 3 and 4: " << g.lca(3, 4) << endl; // Output: 1
    cout << "LCA of 7 and 6: " << g.lca(7, 6) << endl; // Output: 2
    cout << "LCA of 3 and 6: " << g.lca(3, 6) << endl; // Output: 0

    return 0;
}

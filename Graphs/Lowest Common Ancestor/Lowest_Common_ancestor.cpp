// LCA (Lowest Common Ancestor) finder using Euler Tour + Segment Tree + RMQ ka implementation hai.
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    vector<int> height, euler, first, segtree;
    unordered_map<int, bool> visited;
    int n;

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since it's a tree, edges are bidirectional
    }

    void dfs(int node, int h = 0, int parent = -1)
    {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);

        for (int neighbor : adjList[node])
        {
            if (neighbor != parent)
            {
                dfs(neighbor, h + 1, node);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e)
    {
        if (b == e)
        {
            segtree[node] = euler[b];
        }
        else
        {
            int mid = (b + e) / 2;
            build(node * 2, b, mid);
            build(node * 2 + 1, mid + 1, e);
            int l = segtree[node * 2], r = segtree[node * 2 + 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R)
    {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];

        int mid = (b + e) / 2;
        int left = query(node * 2, b, mid, L, R);
        int right = query(node * 2 + 1, mid + 1, e, L, R);

        if (left == -1)
            return right;
        if (right == -1)
            return left;
        return height[left] < height[right] ? left : right;
    }

    void preprocessLCA(int root)
    {
        n = adjList.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.clear();
        dfs(root);

        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    int lca(int u, int v)
    {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

// Example usage
int main()
{
    Graph g;
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};

    for (auto [u, v] : edges)
        g.addEdge(u, v);

    g.preprocessLCA(0); // Root is 0

    cout << "LCA of 3 and 4: " << g.lca(3, 4) << endl;
    cout << "LCA of 3 and 5: " << g.lca(3, 5) << endl;
    cout << "LCA of 5 and 6: " << g.lca(5, 6) << endl;

    return 0;
}

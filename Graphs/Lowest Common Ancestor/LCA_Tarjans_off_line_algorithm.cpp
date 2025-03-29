#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int n;                                 // Number of nodes
    unordered_map<int, list<int>> adjList; // List<int> wali adjacency list
    unordered_map<int, list<int>> queries;
    unordered_map<int, int> ancestor, parent;
    unordered_map<int, bool> visited;

public:
    Graph(int nodes) : n(nodes) {}

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Tree hai, toh bidirectional edges honge
    }

    void addQuery(int u, int v)
    {
        queries[u].push_back(v);
        queries[v].push_back(u);
    }

    int find_set(int v)
    {
        if (parent[v] != v)
            parent[v] = find_set(parent[v]); // Path compression
        return parent[v];
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
            parent[b] = a;
    }

    void dfs(int v)
    {
        visited[v] = true;
        ancestor[v] = v;

        for (int u : adjList[v])
        {
            if (!visited[u])
            {
                dfs(u);
                union_sets(v, u);
                ancestor[find_set(v)] = v;
            }
        }

        for (int other_node : queries[v])
        {
            if (visited[other_node])
            {
                cout << "LCA of " << v << " and " << other_node
                     << " is " << ancestor[find_set(other_node)] << ".\n";
            }
        }
    }

    void compute_LCAs()
    {
        for (auto &[node, _] : adjList)
        {
            parent[node] = node;
            visited[node] = false;
        }
        dfs(0); // Root node se DFS start karna
    }
};

int main()
{
    int n = 8; // Example: 8 nodes
    Graph g(n);

    // Sample edges
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 7}};
    for (auto [u, v] : edges)
        g.addEdge(u, v);

    // Sample queries
    vector<pair<int, int>> queries = {{3, 4}, {7, 6}, {3, 6}};
    for (auto [u, v] : queries)
        g.addQuery(u, v);

    g.compute_LCAs();

    return 0;
}

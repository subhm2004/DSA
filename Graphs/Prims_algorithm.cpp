#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    // Function to add an edge
    void addEdge(int u, int v, int w, bool direction)
    {
        adjList[u].push_back({v, w});
        if (!direction)
        { // If undirected, add the reverse edge
            adjList[v].push_back({u, w});
        }
    }

    // Get the node with the minimum key value
    int get_min_value_node(unordered_map<int, int> &key, unordered_map<int, bool> &mst)
    {
        int temp = INT_MAX, index = -1;
        for (auto &[node, weight] : key)
        {
            if (!mst[node] && weight < temp)
            {
                temp = weight;
                index = node;
            }
        }
        return index;
    }

    // Prim's Algorithm to find MST weight
    int Prims_Algo(int V)
    {
        unordered_map<int, int> key;
        unordered_map<int, bool> mst;
        unordered_map<int, int> parent;

        for (int i = 0; i < V; i++)
        {
            key[i] = INT_MAX;
            mst[i] = false;
            parent[i] = -1;
        }

        key[0] = 0; // Start from node 0

        for (int i = 0; i < V; i++)
        {
            int u = get_min_value_node(key, mst);
            if (u == -1)
                break;

            mst[u] = true;

            for (auto &edge : adjList[u])
            {
                int v = edge.first, w = edge.second;
                if (!mst[v] && w < key[v])
                {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        // Calculate MST sum as per your requirement
        int sum = 0;
        for (int u = 0; u < V; ++u)
        {
            if (parent[u] == -1)
                continue;
            for (auto &edge : adjList[u])
            {
                int v = edge.first, w = edge.second;
                if (v == parent[u])
                {
                    sum += w;
                    break; // Break as we found the parent connection
                }
            }
        }
        return sum;
    }
};

int main()
{
    Solution sol;

    // Adding edges to the graph
    sol.addEdge(0, 1, 2, 0);
    sol.addEdge(1, 2, 3, 0);
    sol.addEdge(0, 3, 6, 0);
    sol.addEdge(1, 3, 8, 0);
    sol.addEdge(1, 4, 5, 0);
    sol.addEdge(2, 4, 7, 0);

    int V = 5; // Number of vertices
    cout << "Minimum Spanning Tree Weight: " << sol.Prims_Algo(V) << endl;
    return 0;
}

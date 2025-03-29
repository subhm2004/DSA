#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <map>
using namespace std;

enum color
{
    WHITE,
    GRAY,
    BLACK
};
/*
  WHITE = unvisited
  GRAY  = Its adjacent nodes are being visited
  BLACK = All its adjacent nodes are visited
*/

// Function to add an edge in a directed or undirected graph
class Solution
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int w, bool direction)
    {
        adjList[u].push_back({v, w});
        if (!direction)
        {
            adjList[v].push_back({u, w}); // Add reverse edge if undirected
        }
    }

    // Function to detect a cycle in a directed graph using DFS with color marking
    bool isCycleUtil(map<int, vector<int>> &adj, int start, vector<int> &NodeColor)
    {
        NodeColor[start] = GRAY; // Mark the current node as visiting

        // Visit all the adjacent nodes
        for (auto x : adj[start])
        {
            if (NodeColor[x] == GRAY)
                return true; // Found a cycle
            if (NodeColor[x] == WHITE && isCycleUtil(adj, x, NodeColor))
                return true; // Recursively check adjacent nodes
        }

        NodeColor[start] = BLACK; // Mark the node as fully processed
        return false;
    }

    // Function to check if there is a cycle in the graph
    bool isCycle(map<int, vector<int>> &adj, int V)
    {
        vector<int> NodeColor(V, WHITE); // Initialize all nodes as unvisited (WHITE)

        for (int i = 0; i < V; i++)
        {
            if (NodeColor[i] == WHITE && isCycleUtil(adj, i, NodeColor))
            {
                return true; // Found a cycle
            }
        }
        return false; // No cycle found
    }
};

int main()
{
    Solution graph;

    int V = 4;
    map<int, vector<int>> adj;

    // Adding directed edges to the graph
    graph.addEdge(0, 1, 0, true); // Directed edge from 0 to 1
    graph.addEdge(0, 2, 0, true); // Directed edge from 0 to 2
    graph.addEdge(1, 2, 0, true); // Directed edge from 1 to 2
    graph.addEdge(2, 0, 0, true); // Directed edge from 2 to 0 (cycle)
    graph.addEdge(2, 3, 0, true); // Directed edge from 2 to 3
    graph.addEdge(3, 3, 0, true); // Self-loop at node 3 (cycle)

    // Check for cycles in the graph
    if (graph.isCycle(adj, V))
    {
        cout << "There is a cycle" << endl;
    }
    else
    {
        cout << "No cycle" << endl;
    }

    return 0;
}

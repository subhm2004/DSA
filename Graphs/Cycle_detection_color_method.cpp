
/*
  WHITE = unvisited
  GRAY  = Its adjacent nodes are being visited
  BLACK = All its adjacent nodes are visited
*/

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

enum color
{
    WHITE,
    GRAY,
    BLACK
};

class Solution
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    // Add edge to directed or undirected graph
    void addEdge(int u, int v, int w, bool direction)
    {
        adjList[u].push_back({v, w});
        if (!direction)
        {
            adjList[v].push_back({u, w});
        }
    }

    // DFS utility function to detect cycle using color method
    bool isCycleUtil(int node, unordered_map<int, int> &nodeColor)
    {
        nodeColor[node] = GRAY;

        for (auto &neighbor : adjList[node])
        {
            int v = neighbor.first;
            if (nodeColor[v] == GRAY)
                return true; // Back edge found
            if (nodeColor[v] == WHITE && isCycleUtil(v, nodeColor))
                return true;
        }

        nodeColor[node] = BLACK;
        return false;
    }

    // Main function to check if there is a cycle
    bool isCycle(int V)
    {
        unordered_map<int, int> nodeColor;
        for (int i = 0; i < V; ++i)
            nodeColor[i] = WHITE;

        for (int i = 0; i < V; ++i)
        {
            if (nodeColor[i] == WHITE)
            {
                if (isCycleUtil(i, nodeColor))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution graph;

    int V = 4;

    // Add directed edges
    graph.addEdge(0, 1, 0, true);
    graph.addEdge(0, 2, 0, true);
    graph.addEdge(1, 2, 0, true);
    graph.addEdge(2, 0, 0, true); // Cycle
    graph.addEdge(2, 3, 0, true);
    graph.addEdge(3, 3, 0, true); // Self-loop (cycle)

    // Check for cycle
    if (graph.isCycle(V))
    {
        cout << "There is a cycle" << endl;
    }
    else
    {
        cout << "No cycle" << endl;
    }

    return 0;
}

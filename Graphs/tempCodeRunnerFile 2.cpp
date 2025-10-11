#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction)
    {
        // direction = 1 -> undirected graph
        adjList[u].push_back({v, wt});
        if (direction == 1)
        {
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }

    void floydWarshall(int n)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        // Diagonal elements set to zero
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        // Initialize distances based on the adjacency list
        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = wt;
            }
        }

        // Core Floyd-Warshall algorithm
        for (int intermediate = 0; intermediate < n; intermediate++)
        {
            for (int start = 0; start < n; start++)
            {
                for (int end = 0; end < n; end++)
                {
                    dist[start][end] = min(dist[start][end], dist[start][intermediate] + dist[intermediate][end]);
                }
            }
        }

        // Detect negative weight cycles
        for (int i = 0; i < n; i++)
        {
            if (dist[i][i] < 0)
            {
                cout << "Negative weight cycle detected!" << endl;
                return;
            }
        }

        // Print the distance matrix
        cout << "Printing distance array: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] == 1e9)
                    cout << "INF, ";
                else
                    cout << dist[i][j] << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;

    // Add edges (directed or undirected)
    g.addEdge(0, 1, 4, 0); // 0 -> 1 with weight 4
    g.addEdge(0, 2, 1, 0); // 0 -> 2 with weight 1
    g.addEdge(2, 1, 2, 0); // 2 -> 1 with weight 2
    g.addEdge(1, 3, 1, 0); // 1 -> 3 with weight 1
    g.addEdge(2, 3, 5, 0); // 2 -> 3 with weight 5

    int n = 4; // Number of vertices (0, 1, 2, 3)

    cout << "Adjacency List:" << endl;
    g.printAdjList();

    cout << "\nRunning Floyd-Warshall Algorithm..." << endl;
    g.floydWarshall(n);

    return 0;
}

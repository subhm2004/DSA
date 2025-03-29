#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int wt, bool direction)
{
    adj[u].push_back({v, wt});
    if (direction == 1)
    {
        adj[v].push_back({u, wt});
    }
}

// Function to print the adjacency list
void printadj(const vector<vector<pair<int, int>>> &adj)
{
    cout << "Adjacency List:" << endl;
    for (int i = 1; i < adj.size(); i++)
    {
        cout << "Node " << i << ":";
        for (auto nbr : adj[i])
        {
            cout << " -> (" << nbr.first << ", " << nbr.second << ")";
        }
        cout << endl;
    }
}

// Function to reconstruct and print the path using the parent array
void printPath(int node, const vector<int> &parent)
{
    if (node == -1)
        return;                      // Base case (source node has no parent)
    printPath(parent[node], parent); // Recursively print the parent
    cout << node << " ";
}

// Function to implement Dijkstra's algorithm with path printing
void shortestDistDijkstra(const vector<vector<pair<int, int>>> &adj, int n, int src)
{
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1); // Parent array to track the path
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initial steps
    dist[src] = 0;
    pq.push({0, src}); // {distance, node}

    while (!pq.empty())
    {
        auto topElement = pq.top();
        pq.pop();

        int nodeDistance = topElement.first;
        int node = topElement.second;

        // Neighbor traversal
        for (auto nbr : adj[node])
        {
            int neighbor = nbr.first;
            int edgeWeight = nbr.second;

            if (nodeDistance + edgeWeight < dist[neighbor])
            {
                // Update distance array and priority queue
                dist[neighbor] = nodeDistance + edgeWeight;
                pq.push({dist[neighbor], neighbor});
                parent[neighbor] = node; // Update the parent
            }
        }
    }

    // Printing the final distances and paths
    cout << "Shortest distances and paths from source " << src << ":" << endl;
    for (int i = 1; i < n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "Node " << i << " -> INF (No path)" << endl;
        }
        else
        {
            cout << "Node " << i << " -> " << dist[i] << " (Path: ";
            printPath(i, parent);
            cout << ")" << endl;
        }
    }
}

int main()
{
    int n = 7;                             // Number of nodes
    vector<vector<pair<int, int>>> adj(n); // Initialize the adjacency list for n nodes

    // Add edges to the graph (without using node 0)
    addEdge(adj, 6, 3, 2, 1);
    addEdge(adj, 6, 1, 14, 1);
    addEdge(adj, 3, 1, 9, 1);
    addEdge(adj, 3, 2, 10, 1);
    addEdge(adj, 1, 2, 7, 1);
    addEdge(adj, 2, 4, 15, 1);
    addEdge(adj, 4, 3, 11, 1);
    addEdge(adj, 6, 5, 9, 1);
    addEdge(adj, 4, 5, 6, 1);

    // Print the adjacency list
    printadj(adj);

    // Run Dijkstra from source node 6
    shortestDistDijkstra(adj, n, 6);

    return 0;
}

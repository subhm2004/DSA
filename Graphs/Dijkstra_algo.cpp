// #include <iostream>       // IMPLEMENTATION USING SET
// #include <vector>
// #include <set>
// #include <limits.h>

// using namespace std;

// // Function to add an edge to the graph
// void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int wt, bool direction)
// {
//     adj[u].push_back({v, wt});
//     if (direction == 1)
//     {
//         adj[v].push_back({u, wt});
//     }
// }

// // Function to print the adjacency list
// void printadj(const vector<vector<pair<int, int>>> &adj)
// {
//     cout << "Adjacency List:" << endl;
//     for (int i = 1; i < adj.size(); i++) // Start from node 1 to avoid printing node 0
//     {
//         cout << "Node " << i << ":";
//         for (auto nbr : adj[i])
//         {
//             cout << " -> (" << nbr.first << ", " << nbr.second << ")";
//         }
//         cout << endl;
//     }
// }

// // Function to implement Dijkstra's algorithm
// void shortestDistDijkstra(const vector<vector<pair<int, int>>> &adj, int n, int src)
// {
//     vector<int> dist(n, INT_MAX);
//     set<pair<int, int>> st;

//     // Initial steps
//     dist[src] = 0;
//     st.insert(make_pair(0, src));

//     while (!st.empty())
//     {
//         // Fetch the smallest element from the set
//         auto topElement = *(st.begin());
//         int nodeDistance = topElement.first;
//         int node = topElement.second;

//         // Pop from set
//         st.erase(st.begin());

//         // Neighbor traversal
//         for (auto nbr : adj[node])
//         {
//             int neighbor = nbr.first;
//             int edgeWeight = nbr.second;

//             if (nodeDistance + edgeWeight < dist[neighbor])
//             {
//                 // Finding entry in set
//                 auto result = st.find(make_pair(dist[neighbor], neighbor));
//                 // If found, then remove
//                 if (result != st.end())
//                 {
//                     st.erase(result);
//                 }
//                 // Update distance array and set
//                 dist[neighbor] = nodeDistance + edgeWeight;
//                 st.insert(make_pair(dist[neighbor], neighbor));
//             }
//         }
//     }

//     // Printing the final distances
//     cout << "Shortest distances from source " << src << ":" << endl;
//     for (int i = 1; i < n; i++) // Start from node 1 to avoid printing node 0
//     {
//         // Print "INF" for unreachable nodes
//         if (dist[i] == INT_MAX)
//         {
//             cout << "Node " << i << " -> INF" << endl;
//         }
//         else
//         {
//             cout << "Node " << i << " -> " << dist[i] << endl;
//         }
//     }
// }

// int main()
// {
//     int n = 7;                             // Number of nodes
//     vector<vector<pair<int, int>>> adj(n); // Initialize the adjacency list for n nodes

//     // Add edges to the graph (without using node 0)
//     addEdge(adj, 6, 3, 2, 1);
//     addEdge(adj, 6, 1, 14, 1);
//     addEdge(adj, 3, 1, 9, 1);
//     addEdge(adj, 3, 2, 10, 1);
//     addEdge(adj, 1, 2, 7, 1);
//     addEdge(adj, 2, 4, 15, 1);
//     addEdge(adj, 4, 3, 11, 1);
//     addEdge(adj, 6, 5, 9, 1);
//     addEdge(adj, 4, 5, 6, 1);

//     // Print the adjacency list
//     printadj(adj);

//     // Run Dijkstra from source node 6
//     shortestDistDijkstra(adj, n, 6);

//     return 0;
// }
#include <iostream> // IMPLEMENTATION USING PRIORITY QUEUE
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
    for (int i = 1; i < adj.size(); i++) // Start from node 1 to avoid printing node 0
    {
        cout << "Node " << i << ":";
        for (auto nbr : adj[i])
        {
            cout << " -> (" << nbr.first << ", " << nbr.second << ")";
        }
        cout << endl;
    }
}

// Function to implement Dijkstra's algorithm using priority queue
void shortestDistDijkstra(const vector<vector<pair<int, int>>> &adj, int n, int src)
{
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initial steps
    dist[src] = 0;
    pq.push({0, src}); // {distance, node}

    while (!pq.empty())
    {
        // Fetch the smallest element from the priority queue
        auto [nodeDistance, node] = pq.top();
        pq.pop();

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
            }
        }
    }

    // Printing the final distances
    cout << "Shortest distances from source " << src << ":" << endl;
    for (int i = 1; i < n; i++) // Start from node 1 to avoid printing node 0
    {
        // Print "INF" for unreachable nodes
        if (dist[i] == INT_MAX)
        {
            cout << "Node " << i << " -> INF" << endl;
        }
        else
        {
            cout << "Node " << i << " -> " << dist[i] << endl;
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

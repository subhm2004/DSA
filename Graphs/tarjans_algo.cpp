#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    // Add an edge to the graph
    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 1)
        { // Undirected graph
            adjList[v].push_back(u);
        }
    }

    // Utility function to perform DFS and find bridges
    void findBridgesDFS(
        int currentNode,
        int parentNode,
        int &timer,
        vector<int> &discoveryTime,
        vector<int> &lowestTime,
        unordered_map<int, bool> &visited,
        vector<pair<int, int>> &ans)
    {
        visited[currentNode] = true;
        discoveryTime[currentNode] = timer;
        lowestTime[currentNode] = timer;
        timer++;

        // Traverse all neighbors
        for (auto neighbor : adjList[currentNode])
        {
            if (neighbor == parentNode)
            {
                continue; // Skip the parent node
            }

            if (!visited[neighbor])
            {
                // Recursive DFS call
                findBridgesDFS(neighbor, currentNode, timer, discoveryTime, lowestTime, visited, ans);

                // Update the lowest discovery time
                lowestTime[currentNode] = min(lowestTime[currentNode], lowestTime[neighbor]);

                // Check if the edge is a bridge and add to answer list
                if (lowestTime[neighbor] > discoveryTime[currentNode])
                {
                    ans.push_back({currentNode, neighbor});
                }
            }
            else
            {
                // Update the lowest discovery time if the neighbor is already visited
                lowestTime[currentNode] = min(lowestTime[currentNode], discoveryTime[neighbor]);
            }
        }
    }

    // Function to find bridges in the graph
    void findBridges(int n)
    {
        vector<int> discoveryTime(n, -1);
        vector<int> lowestTime(n, -1);
        unordered_map<int, bool> visited;
        int timer = 0;
        vector<pair<int, int>> ans;

        // Perform DFS for all connected components
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                findBridgesDFS(i, -1, timer, discoveryTime, lowestTime, visited, ans);
            }
        }

        // Output the bridges in the graph
        cout << "Bridges in the graph are:" << endl;
        for (auto bridge : ans)
        {
            cout << bridge.first << " -- " << bridge.second << endl;
        }
    }
};

int main()
{
    Graph g;

    int n, m; // Number of nodes and edges
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    cout << "Enter the edges (u v): " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1); // 1 indicates an undirected graph
    }

    g.findBridges(n);

    return 0;
}

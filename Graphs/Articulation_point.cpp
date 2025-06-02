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

    // Utility function to perform DFS and find bridges and articulation points
    void find_Articulation_Points_DFS(
        int currentNode,
        int parentNode,
        int &timer,
        vector<int> &discoveryTime,
        vector<int> &lowestTime,
        unordered_map<int, bool> &visited,
        unordered_map<int, bool> &articulation_Points,
        int &childCount)
    {
        visited[currentNode] = true;
        discoveryTime[currentNode] = timer;
        lowestTime[currentNode] = timer;
        timer++;

        childCount = 0;

        // Traverse all neighbors
        for (auto neighbor : adjList[currentNode])
        {
            if (neighbor == parentNode)
            {
                continue; // Skip the parent node
            }

            if (!visited[neighbor])
            {
                childCount++;
                find_Articulation_Points_DFS(neighbor, currentNode, timer, discoveryTime, lowestTime, visited, articulation_Points, childCount);

                // Update the lowest discovery time
                lowestTime[currentNode] = min(lowestTime[currentNode], lowestTime[neighbor]);

                // Articulation Point condition 1: If current node is the root and has more than one child
                if (parentNode == -1 && childCount > 1)
                {
                    articulation_Points[currentNode] = true;
                }

                // Articulation Point condition 2: If the lowest time of the neighbor is greater than the discovery time of current node
                if (parentNode != -1 && lowestTime[neighbor] >= discoveryTime[currentNode])
                {
                    articulation_Points[currentNode] = true;
                }
            }
            else
            {
                // Update the lowest discovery time if the neighbor is already visited
                lowestTime[currentNode] = min(lowestTime[currentNode], discoveryTime[neighbor]);
            }
        }
    }

    // Function to find articulation points in the graph
    void findArticulation_Points(int n, vector<int> &articulation_PointsVector)
    {
        vector<int> discoveryTime(n, -1);
        vector<int> lowestTime(n, -1);
        unordered_map<int, bool> visited;
        unordered_map<int, bool> articulation_PointsMap;
        int timer = 0;

        // Perform DFS for all connected components
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int childCount = 0;
                find_Articulation_Points_DFS(i, -1, timer, discoveryTime, lowestTime, visited, articulation_PointsMap, childCount);
            }
        }

        // Store the articulation points in the vector
        for (auto point : articulation_PointsMap)
        {
            if (point.second)
            {
                articulation_PointsVector.push_back(point.first);
            }
        }
    }

    // Function to find bridges in the graph
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

    // Predefined graph input
    int n = 5, m = 5; // Number of nodes and edges
    cout << "Enter the number of nodes and edges: " << endl;
    cout << "Number of nodes: " << n << ", Number of edges: " << m << endl;

    // Predefined edges (u v)
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {3, 4}};

    cout << "Enter the edges (u v): " << endl;
    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        g.addEdge(u, v, 1); // 1 indicates an undirected graph
    }

    // Vector to store articulation points
    vector<int> articulation_PointsVector;

    // Find and display bridges and articulation points
    g.findBridges(n);
    g.findArticulation_Points(n, articulation_PointsVector);

    // Output the articulation points
    cout << "Articulation points in the graph are:" << endl;
    for (int point : articulation_PointsVector)
    {
        cout << point << endl;
    }

    return 0;
}

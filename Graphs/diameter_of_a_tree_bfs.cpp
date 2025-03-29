#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Helper function to perform BFS and return the farthest node and its distance
    pair<int, int> BFS(unordered_map<int, list<int>> &adj, int start)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        q.push(start);
        visited[start] = true;

        int farthestNode = start, distance = 0;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int curr = q.front();
                q.pop();
                farthestNode = curr;

                for (int neighbor : adj[curr])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            if (!q.empty())
                distance++;
        }

        return {farthestNode, distance};
    }

    // Function to find the diameter of a tree using two BFS traversals
    int findDiameter(unordered_map<int, list<int>> &adj)
    {
        // Step-1: Find the farthest node from a random node (0)
        auto [farthestNode, _] = BFS(adj, 0);

        // Step-2: Find the farthest node from the node we got above (one end of the diameter)
        auto [otherEndNode, diameter] = BFS(adj, farthestNode);

        return diameter;
    }

    // Function to build an adjacency list from edge list using list<int>
    unordered_map<int, list<int>> buildAdj(const vector<vector<int>> &edges)
    {
        unordered_map<int, list<int>> adj;
        for (const auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }

    int treeDiameter(vector<vector<int>> &edges)
    {
        unordered_map<int, list<int>> adj = buildAdj(edges);
        return findDiameter(adj);
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 4}, {4, 5}};
    cout << sol.treeDiameter(edges) << endl; // Output: 4
    return 0;
}

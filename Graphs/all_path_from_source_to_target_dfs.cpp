#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &graph, int node, vector<int> &path, vector<vector<int>> &result)
    {
        path.push_back(node);

        if (node == graph.size() - 1)
        {
            result.push_back(path); // If last node is the target, store the path
        }
        else
        {
            for (int neighbor : graph[node])
            {
                dfs(graph, neighbor, path, result);
            }
        }

        path.pop_back(); // Backtrack
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> result;
        vector<int> path;
        dfs(graph, 0, path, result);
        return result;
    }
};

// Example Usage
int main()
{
    Solution sol;
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> paths = sol.allPathsSourceTarget(graph);

    for (auto &path : paths)
    {
        for (int node : path)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}

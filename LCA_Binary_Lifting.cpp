#include <bits/stdc++.h>
using namespace std;

class Binary_Lifting
{
private:
    int n, LOG;
    vector<vector<int>> up;
    vector<int> depth;

public:
    Binary_Lifting(int n, const vector<int> &parent)
    {
        this->n = n;
        LOG = ceil(log2(n)) + 1;
        up.assign(n, vector<int>(LOG, -1));
        depth.assign(n, 0);

        // Set 2^0-th parent
        for (int i = 0; i < n; ++i)
        {
            up[i][0] = parent[i];
        }

        // Fill depth[] using DFS
        for (int i = 0; i < n; ++i)
        {
            if (parent[i] == -1)
                dfs(i, 0, parent);
        }

        // Fill 2^j-th ancestors
        for (int j = 1; j < LOG; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                int prev = up[i][j - 1];
                if (prev != -1)
                    up[i][j] = up[prev][j - 1];
            }
        }
    }

    void dfs(int node, int d, const vector<int> &parent)
    {
        depth[node] = d;
        for (int i = 0; i < n; ++i)
        {
            if (parent[i] == node)
            {
                dfs(i, d + 1, parent);
            }
        }
    }

    int get_Kth_Ancestor(int node, int k)
    {
        for (int i = 0; i < LOG; ++i)
        {
            if (k & (1 << i))
            {
                node = up[node][i];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }

    int find_LCA(int u, int v)
    {
        if (depth[u] < depth[v])
            swap(u, v);
        u = get_Kth_Ancestor(u, depth[u] - depth[v]);
        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; --i)
        {
            if (up[u][i] != -1 && up[u][i] != up[v][i])
            {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
};

int main()
{
    // Bigger tree example
    // Tree:
    //               0
    //           /   |   \
    //         1     2     3
    //        / \   / \
    //       4   5 6   7
    //      /     / \
    //     8     9  10

    int n = 11;
    vector<int> parent = {-1, 0, 0, 0, 1, 1, 2, 2, 4, 6, 6};

    Binary_Lifting bl(n, parent);

    // Test get_Kth_Ancestor
    cout << "2nd ancestor of 8: " << bl.get_Kth_Ancestor(8, 2) << endl;   // Output: 1
    cout << "3rd ancestor of 9: " << bl.get_Kth_Ancestor(9, 3) << endl;   // Output: 0
    cout << "1st ancestor of 10: " << bl.get_Kth_Ancestor(10, 1) << endl; // Output: 6

    // Test find_LCA
    cout << "LCA of 5 and 8: " << bl.find_LCA(5, 8) << endl;   // Output: 1
    cout << "LCA of 8 and 10: " << bl.find_LCA(8, 10) << endl; // Output: 0
    cout << "LCA of 9 and 10: " << bl.find_LCA(9, 10) << endl; // Output: 6
    cout << "LCA of 7 and 10: " << bl.find_LCA(7, 10) << endl; // Output: 2
    cout << "LCA of 3 and 10: " << bl.find_LCA(3, 10) << endl; // Output: 0

    return 0;
}
// This code implements Binary Lifting for Lowest Common Ancestor (LCA) queries in a tree.
// It allows efficient retrieval of the k-th ancestor of a node and the LCA of two nodes.
// The tree is represented using a parent array, where the index represents the node and the value
// at that index represents the parent of the node. The depth of each node is calculated using
// a depth-first search (DFS) traversal. The ancestors are stored in a 2D vector `up`, where `up[i][j]` represents the 2^j-th ancestor of node i.
// The main function demonstrates the usage of the Binary_Lifting class with a sample tree
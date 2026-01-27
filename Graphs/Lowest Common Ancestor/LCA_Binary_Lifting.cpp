#include <bits/stdc++.h>
using namespace std;

class BinaryLifting {
private:
    int n;
    int LOG;
    unordered_map<int, list<int>> adjList;
    vector<vector<int>> up;    // up[v][j] = 2^j-th ancestor of v
    vector<int> depth;
    vector<int> parent;

public:
    BinaryLifting(int n) {
        this->n = n;
        adjList.clear();
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // tree undirected
    }

    void dfs(int node, int par) {
        parent[node] = par;
        for (int nei : adjList[node]) {
            if (nei == par) continue;
            depth[nei] = depth[node] + 1;
            dfs(nei, node);
        }
    }

    void build(int root) {
        depth.assign(n, 0);
        parent.assign(n, -1);

        // depth + parent fill
        dfs(root, -1);

        LOG = ceil(log2(n)) + 1;
        up.assign(n, vector<int>(LOG, -1));

        // 2^0 level parents
        for (int i = 0; i < n; i++)
            up[i][0] = parent[i];

        // Binary lifting DP
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[i][j-1] != -1)
                    up[i][j] = up[ up[i][j-1] ][j-1];
            }
        }
    }

    // k-th ancestor finder
    int jump(int node, int k) {
        for (int i = 0; i < LOG && node != -1; i++) {
            if (k & (1 << i))
                node = up[node][i];
        }
        return node;
    }

    int getKthAncestor(int node, int k) {
        return jump(node, k);
    }

    // LCA finder
    int lca(int u, int v) {
        // Step 1: depth align
        if (depth[u] < depth[v])
            v = jump(v, depth[v] - depth[u]);
        else if (depth[u] > depth[v])
            u = jump(u, depth[u] - depth[v]);

        if (u == v) return u;

        // Step 2: lift both up until parents same
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
};

int main() {
    int n = 8;
    BinaryLifting bl(n);

    // Tree:
    //        0
    //      /   \
    //     1     2
    //    / \   / \
    //   3   4 5   6
    //         |
    //         7

    vector<pair<int,int>> edges = {
        {0,1},{0,2},{1,3},{1,4},{2,5},{2,6},{5,7}
    };

    for (auto &e : edges)
        bl.addEdge(e.first, e.second);

    bl.build(0);

    cout << "LCA(3,4) = " << bl.lca(3,4) << endl; // 1
    cout << "LCA(7,6) = " << bl.lca(7,6) << endl; // 2
    cout << "LCA(3,6) = " << bl.lca(3,6) << endl; // 0
    cout << "LCA(4,7) = " << bl.lca(4,7) << endl; // 0

    cout << "3rd ancestor of 7 = " << bl.getKthAncestor(7, 3) << endl; // 0
    cout << "1st ancestor of 7 = " << bl.getKthAncestor(7, 1) << endl; // 5
    cout << "2nd ancestor of 7 = " << bl.getKthAncestor(7, 2) << endl; // 2
    cout << "4th ancestor of 7 = " << bl.getKthAncestor(7, 4) << endl; // -1

    return 0;
}

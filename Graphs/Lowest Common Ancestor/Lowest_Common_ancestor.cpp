// LCA (Lowest Common Ancestor) finder using Euler Tour + Segment Tree + RMQ ka implementation hai.
#include <bits/stdc++.h>
using namespace std;

class LCAEuler {
public:
    vector<vector<int>> adj;          // adjacency list
    vector<int> depth;                // depth of nodes
    vector<int> eulerTour;            // euler tour list
    vector<int> firstOccur;           // first occurrence index in euler tour
    vector<int> segmentTree;          // segment tree for RMQ
    int n;                            // number of nodes

    LCAEuler(int n) {
        this->n = n;
        adj.resize(n);
        depth.resize(n);
        firstOccur.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node, int parent, int d) {
        depth[node] = d;
        firstOccur[node] = eulerTour.size();
        eulerTour.push_back(node);

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            dfs(neighbor, node, d + 1);
            eulerTour.push_back(node);
        }
    }

    void buildSegmentTree(int idx, int left, int right) {
        if (left == right) {
            segmentTree[idx] = eulerTour[left];
            return;
        }

        int mid = (left + right) / 2;
        int leftChild = idx * 2 + 1;
        int rightChild = idx * 2 + 2;

        buildSegmentTree(leftChild, left, mid);
        buildSegmentTree(rightChild, mid + 1, right);

        int lNode = segmentTree[leftChild];
        int rNode = segmentTree[rightChild];
        segmentTree[idx] = (depth[lNode] < depth[rNode]) ? lNode : rNode;
    }

    int querySegmentTree(int idx, int left, int right, int ql, int qr) {
        if (right < ql || left > qr) return -1;
        if (left >= ql && right <= qr) return segmentTree[idx];

        int mid = (left + right) / 2;
        int leftChild = idx * 2 + 1;
        int rightChild = idx * 2 + 2;

        int q1 = querySegmentTree(leftChild, left, mid, ql, qr);
        int q2 = querySegmentTree(rightChild, mid + 1, right, ql, qr);

        if (q1 == -1) return q2;
        if (q2 == -1) return q1;
        return depth[q1] < depth[q2] ? q1 : q2;
    }

    void preprocess(int root = 0) {
        eulerTour.clear();
        dfs(root, -1, 0);

        int m = eulerTour.size();
        segmentTree.assign(4 * m, -1);
        buildSegmentTree(0, 0, m - 1);
    }

    int lca(int u, int v) {
        int left = firstOccur[u];
        int right = firstOccur[v];
        if (left > right) swap(left, right);
        return querySegmentTree(0, 0, eulerTour.size() - 1, left, right);
    }
};

// Example usage
int main() {
    int n = 7;
    LCAEuler tree(n);

    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}
    };

    for (auto [u, v] : edges) tree.addEdge(u, v);

    tree.preprocess(0); // root = 0

    cout << "LCA of 3 and 4: " << tree.lca(3, 4) << endl; // expected: 1
    cout << "LCA of 3 and 5: " << tree.lca(3, 5) << endl; // expected: 0
    cout << "LCA of 5 and 6: " << tree.lca(5, 6) << endl; // expected: 2
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <tuple>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unionByRank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    int countComponents() {
        int components = 0;
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] == i)
                components++;
        }
        return components;
    }
};

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjList; // node -> [(neighbor, weight)]
    vector<tuple<int, int, int>> edges; // (u, v, weight)

    void addEdge(int u, int v, int weight, bool directed) {
        adjList[u].push_back({v, weight});
        edges.push_back({u, v, weight});
        if (!directed) {
            adjList[v].push_back({u, weight});
            edges.push_back({v, u, weight});
        }
    }

    void printAdjacencyListWithWeights() {
        cout << "Adjacency List with Weights:" << endl;
        for (const auto &node : adjList) {
            cout << "Node " << node.first << ":";
            for (const auto &nbr : node.second) {
                cout << " -> (" << nbr.first << ", " << nbr.second << ")";
            }
            cout << endl;
        }
    }

    int kruskalMST(int n) {
        sort(edges.begin(), edges.end(), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
            return get<2>(a) < get<2>(b);
        });

        UnionFind uf(n);
        int mstWeight = 0;

        for (auto &edge : edges) {
            int u = get<0>(edge);
            int v = get<1>(edge);
            int weight = get<2>(edge);

            if (uf.find(u) != uf.find(v)) {
                uf.unionByRank(u, v);
                mstWeight += weight;
            }
        }

        return mstWeight;
    }

    bool hasCycle() {
        UnionFind uf(adjList.size());
        for (auto &edge : edges) {
            int u = get<0>(edge);
            int v = get<1>(edge);
            if (uf.find(u) == uf.find(v)) {
                return true;
            }
            uf.unionByRank(u, v);
        }
        return false;
    }

    int findConnectedComponents() {
        UnionFind uf(adjList.size());
        for (auto &edge : edges) {
            int u = get<0>(edge);
            int v = get<1>(edge);
            uf.unionByRank(u, v);
        }
        return uf.countComponents();
    }
};

int main() {
    Graph g;
    int n = 6; // total number of nodes

    g.addEdge(0, 1, 10, false);
    g.addEdge(0, 2, 6, false);
    g.addEdge(0, 3, 5, false);
    g.addEdge(1, 3, 15, false);
    g.addEdge(2, 3, 4, false);

    g.printAdjacencyListWithWeights();

    cout << "Minimum Spanning Tree Weight: " << g.kruskalMST(n) << endl;

    cout << "Number of Connected Components: " << g.findConnectedComponents() << endl;

    if (g.hasCycle()) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}

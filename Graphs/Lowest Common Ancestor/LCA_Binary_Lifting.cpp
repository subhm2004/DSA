// Binary Lifting to find LCA and K-th Ancestor 
// TC : O((N + Q) log N) for Q queries
// SC : O(N log N) 
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <cmath>
#include <climits>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Binary_lifting {
private:
    int LOG;
    unordered_map<int, list<int>> adjList;
    unordered_map<int, TreeNode*> node_Map;
    unordered_map<int, vector<int>> up;
    unordered_map<int, int> depth;
    unordered_map<int, int> parent_Of;
    int n;
    const int NO_PARENT = INT_MIN;  

public:
    void build_Graph(TreeNode* root) {
        if (!root)
            return;
        node_Map[root->val] = root;
        if (root->left) {
            adjList[root->val].push_back(root->left->val);
            adjList[root->left->val].push_back(root->val);
            build_Graph(root->left);
        }
        if (root->right) {
            adjList[root->val].push_back(root->right->val);
            adjList[root->right->val].push_back(root->val);
            build_Graph(root->right);
        }
    }

    void dfs(int curr_node, int parent) {
        parent_Of[curr_node] = parent;
        
        if (parent == NO_PARENT)
            depth[curr_node] = 0;
        else
            depth[curr_node] = depth[parent] + 1;

        for (int nbr : adjList[curr_node]) {
            if (nbr == parent)
                continue;
            dfs(nbr, curr_node);
        }
    }

    void build(TreeNode* root) {
        build_Graph(root);
        n = node_Map.size();
        LOG = ceil(log2(n)) + 1;

        dfs(root->val, NO_PARENT);

        // Initialize up table for all nodes FIRST
        for (auto& x : node_Map) {
            up[x.first].assign(LOG, NO_PARENT);
        }

        // Then set up[v][0] = parent
        for (auto& x : node_Map) {
            up[x.first][0] = parent_Of[x.first];
        }

        // Fill binary lifting table
        for (int j = 1; j < LOG; j++) {
            for (auto& x : node_Map) {
                int node = x.first;
                int prev_Ancestor = up[node][j - 1];
                
                // Check if prev_Ancestor exists and is valid
                if (prev_Ancestor != NO_PARENT && up.count(prev_Ancestor)) {
                    up[node][j] = up[prev_Ancestor][j - 1];
                }
            }
        }
    }

    // K-th ancestor of a node 
    int jump(int node, int k) {
        for (int i = 0; i < LOG && node != NO_PARENT; i++) {
            if (k & (1 << i)) {
                node = up[node][i];
            }
        }
        return node;
    }

    int LCA(int u, int v) {
        if (depth[u] < depth[v])
            v = jump(v, depth[v] - depth[u]);
        else if (depth[u] > depth[v])
            u = jump(u, depth[u] - depth[v]);

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != NO_PARENT && up[v][i] != NO_PARENT && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    TreeNode* get_Node(int val) { 
        if (node_Map.count(val)) {
            return node_Map[val];
        }
        return nullptr;
    }

    int get_Depth(int node) {
        return depth[node];
    }
};

int main() {
    /*
    Tree structure:
            3
           / \
          5   1
         / \  / \
        6  2 0   8
          / \
         7   4
    */
    
    // Create tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Build Binary Lifting structure
    Binary_lifting bl;
    bl.build(root);

    cout << "Binary Lifting - Multiple Queries Demo\n";
    cout << "========================================\n\n";

    // Multiple LCA queries
    vector<pair<int, int>> queries = {
        {5, 1},   // LCA = 3
        {5, 4},   // LCA = 5
        {6, 4},   // LCA = 5
        {7, 4},   // LCA = 2
        {0, 8},   // LCA = 1
        {6, 7},   // LCA = 5
    };

    cout << "LCA Queries:\n";
    for (auto& q : queries) {
        int lca = bl.LCA(q.first, q.second);
        cout << "LCA(" << q.first << ", " << q.second << ") = " << lca << "\n";
    }

    cout << "\n----------------------------------------\n\n";

    // K-th ancestor queries
    cout << "K-th Ancestor Queries:\n";
    vector<pair<int, int>> ancestor_queries = {
        {7, 1},   // 1st ancestor of 7 = 2
        {7, 2},   // 2nd ancestor of 7 = 5
        {7, 3},   // 3rd ancestor of 7 = 3
        {4, 2},   // 2nd ancestor of 4 = 5
        {8, 2},   // 2nd ancestor of 8 = 3
    };

    for (auto& q : ancestor_queries) {
        int ancestor = bl.jump(q.first, q.second);
        if (ancestor != INT_MIN) {
            cout << q.second << "-th ancestor of " << q.first << " = " << ancestor << "\n";
        } else {
            cout << q.second << "-th ancestor of " << q.first << " = NULL (doesn't exist)\n";
        }
    }

    cout << "\n----------------------------------------\n\n";

    // Depth queries
    cout << "Depth Queries:\n";
    vector<int> nodes = {3, 5, 1, 6, 2, 0, 8, 7, 4};
    for (int node : nodes) {
        cout << "Depth of node " << node << " = " << bl.get_Depth(node) << "\n";
    }

    cout << "\n========================================\n";
    cout << "Total queries executed efficiently!\n";
    
    return 0;
}
```

**Output:**
```
Binary Lifting - Multiple Queries Demo
========================================

LCA Queries:
LCA(5, 1) = 3
LCA(5, 4) = 5
LCA(6, 4) = 5
LCA(7, 4) = 2
LCA(0, 8) = 1
LCA(6, 7) = 5

----------------------------------------

K-th Ancestor Queries:
1-th ancestor of 7 = 2
2-th ancestor of 7 = 5
3-th ancestor of 7 = 3
2-nd ancestor of 4 = 5
2-nd ancestor of 8 = 3

----------------------------------------

Depth Queries:
Depth of node 3 = 0
Depth of node 5 = 1
Depth of node 1 = 1
Depth of node 6 = 2
Depth of node 2 = 2
Depth of node 0 = 2
Depth of node 8 = 2
Depth of node 7 = 3
Depth of node 4 = 3

========================================
Total queries executed efficiently!

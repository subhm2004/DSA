#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from a vector (level order input)
TreeNode *buildTree(const vector<int> &values)
{
    if (values.empty() || values[0] == -1)
        return nullptr;

    TreeNode *root = new TreeNode(values[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < values.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (values[i] != -1)
        {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != -1)
        {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Function to print the tree in level order (for verification)
void printTree(TreeNode *root)
{
    if (!root)
    {
        cout << "Tree is empty.\n";
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();

        if (current)
            cout << current->val << " ";
        else
            cout << "null ";

        if (current)
        {
            q.push(current->left);
            q.push(current->right);
        }
    }
    cout << endl;
}

class Solution
{
public:
    vector<vector<int>> findLeaves(TreeNode *root)
    {
        vector<vector<int>> result;
        traverse(root, result);
        return result;
    }

private:
    int traverse(TreeNode *node, vector<vector<int>> &result)
    {
        if (!node)
            return -1;

        int leftHeight = traverse(node->left, result);
        int rightHeight = traverse(node->right, result);
        int currentHeight = max(leftHeight, rightHeight) + 1;

        if (currentHeight >= result.size())
            result.resize(currentHeight + 1);

        result[currentHeight].push_back(node->val);

        return currentHeight;
    }
};

// Function to print the result
void printResult(const vector<vector<int>> &result)
{
    for (const auto &level : result)
    {
        cout << "[ ";
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << "]\n";
    }
}

int main()
{
    vector<int> values = {1, 2, 3, 4, 5, -1, -1}; // -1 represents nullptr
    TreeNode *root = buildTree(values);

    cout << "Level-order tree: ";
    printTree(root);

    Solution sol;
    vector<vector<int>> result = sol.findLeaves(root);

    cout << "Leaves by level:\n";
    printResult(result);

    return 0;
}

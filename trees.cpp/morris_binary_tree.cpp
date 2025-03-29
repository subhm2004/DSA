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

// Function to build a Binary Tree from level-order input
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

        // Left child
        if (values[i] != -1)
        {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < values.size() && values[i] != -1)
        {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Morris Inorder Traversal (O(1) space)
void morrisTraversal(TreeNode *root)
{
    TreeNode *current = root;

    while (current != nullptr)
    {
        if (current->left == nullptr)
        {
            cout << current->val << " ";
            current = current->right;
        }
        else
        {
            TreeNode *predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current)
                predecessor = predecessor->right;

            if (predecessor->right == nullptr)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                predecessor->right = nullptr;
                cout << current->val << " ";
                current = current->right;
            }
        }
    }
}

// Driver Code
int main()
{
    vector<int> values = {1, 2, 3, -1, 5, -1, 4}; // -1 means NULL
    TreeNode *root = buildTree(values);

    cout << "Morris Inorder Traversal: ";
    morrisTraversal(root);
    cout << endl;

    return 0;
}

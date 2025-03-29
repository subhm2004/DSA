#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a value into BST
TreeNode *insertBST(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// Function to build BST from a given vector of values
TreeNode *buildBST(const vector<int> &values)
{
    TreeNode *root = nullptr;
    for (int val : values)
    {
        if (val != -1) // Ignore -1 as it represents NULL in input
            root = insertBST(root, val);
    }
    return root;
}

// Inorder Traversal (Recursive)
void inorderTraversal(TreeNode *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Morris Inorder Traversal (Space Optimized)
void morrisTraversal(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr)
    {
        if (!curr->left)
        {
            cout << curr->val << " ";
            curr = curr->right;
        }
        else
        {
            TreeNode *pre = curr->left;
            while (pre->right && pre->right != curr)
            {
                pre = pre->right;
            }

            if (!pre->right)
            {
                pre->right = curr; // Create a thread
                curr = curr->left;
            }
            else
            {
                pre->right = nullptr; // Remove the thread
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    vector<int> values = {5, 3, 7, 2, 4, 6, 8}; // BST values
    TreeNode *root = buildBST(values);

    cout << "Inorder Traversal (Recursive): ";
    inorderTraversal(root);
    cout << endl;

    cout << "Inorder Traversal (Morris Traversal - Space Optimized): ";
    morrisTraversal(root);
    cout << endl;

    return 0;
}

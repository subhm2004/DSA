#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *CreateTree()
{
    int val;
    cout << "Enter data (-1 for NULL): ";
    cin >> val;
    if (val == -1)
    {
        return NULL;
    }
    Node *root = new Node(val);
    root->left = CreateTree();
    root->right = CreateTree();
    return root; // Missing return statement fixed
}

int maximumDepth(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = maximumDepth(root->left);
    int right = maximumDepth(root->right);
    return max(left, right) + 1;
}

bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int left = maximumDepth(root->left);
    int right = maximumDepth(root->right);
    bool difference = (abs(left - right) <= 1);
    bool lsubtree = isBalanced(root->left);
    bool rsubtree = isBalanced(root->right);
    return difference && lsubtree && rsubtree;
}

int main()
{
    Node *root = CreateTree();
    if (isBalanced(root))
    {
        cout << "The tree is height balanced." << endl;
    }
    else
    {
        cout << "The tree is NOT height balanced." << endl;
    }
    return 0;
}

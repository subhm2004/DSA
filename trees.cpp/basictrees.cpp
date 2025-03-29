#include<iostream>
#include<queue>
using namespace std;
//  the below NODE logic creates a node and initializes it.
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this-> data= val;
        this-> left= NULL;
        this-> right= NULL;
    }
};
Node* CreateTree(){
    int data;
    cout<< "Enter the data of node"<< endl;
    cin>> data;
    if(data== -1){
        return NULL;
    }
    // Create Node
    Node* root= new Node(data);
    // Create Left Subtree
    root-> left= CreateTree();
    // Create Right Subtree
    root-> right= CreateTree();
    return root;

}
// traversals
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<< root-> data<< "->";
    preorder(root-> left);
    preorder(root-> right);

}
void inorder(Node* root){
    if(root== NULL){
        return;
    }
    inorder(root-> left);
    cout<< root-> data<< "->";
    inorder(root->right);
}
void postorder(Node* root){
    if(root== NULL){
        return;
    }
    postorder(root-> left);
    postorder(root-> right);
    cout<< root-> data<< "->";
}
queue<Node*>q;
void levelorder(Node* root){
    q.push(root);
    while(!q.empty()){
        cout << root-> data << "->";
             q.push(root->left);
            q.push(root->right);
        q.pop();
        root = q.front();
    }
}
void levelordertraversal(Node* root){
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* newnode= q.front();
        q.pop();
        if(newnode!= NULL){
            cout<< newnode-> data<< "->";
            if(newnode-> left!= NULL){
                q.push(newnode-> left);
            }
            if(newnode-> right!= NULL){
                q.push(newnode-> right);
            }
        }
        else{
            cout<< endl;
            if(!q.empty()){
                q.push(NULL);

            }
        }
    }
}
int main(){
    Node* root = CreateTree();
    levelordertraversal(root);
    // preorder(root);
    // cout<< endl;
    // inorder(root);
    // cout<< endl;
    // postorder(root);
    // cout<< endl;

}
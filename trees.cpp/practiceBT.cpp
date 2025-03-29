#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this-> data= val;
        this-> left= NULL;
        this->right= NULL;
    }
};
Node* CreateTree(){
    int data;
    cout<< "enter node data"<< endl;
    cin>> data;
    if(data== -1){
        return NULL;
    }
    // create node
    Node* root= new Node(data);
    // craete left subtree
    root-> left= CreateTree();
    // right subtree
    root-> right= CreateTree();
}
// 4 traversals
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<< root-> data<< "->";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root== NULL){
        return;
    }
    inorder(root->left);
    cout<< root->data<<"->";
    inorder(root->right);
}
void postorder(Node* root){
    if(root== NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<< root-> data<< "->";
}
void levelorder(Node* root){
    if(root== NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* newnode= q.front();
        q.pop();
        cout<< newnode-> data<< "->";
        if(newnode-> left!= NULL){
            q.push(newnode-> left);
        }
        if(newnode-> right!= NULL){
            q.push(newnode-> right);
        }
    }
}
void levelordertraversal(Node* root){
    if(root== NULL){
        return;
    }
    queue<Node*>q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty()){
        Node* newnode= q1.front();
        q1.pop();
        if(newnode!= NULL){
            cout<< newnode-> data<< "->";
            if(newnode-> left!= NULL){
                q1.push(newnode-> left);
            }
            if(newnode-> right!= NULL){
                q1.push(newnode-> right);
            }
        }
        else {
            cout<< endl;
            if(!q1.empty()){
                q1.push(NULL);
            }
        }
    }
}
int main(){
    Node* root= CreateTree();
    cout<< "INORDER"<< endl;
    inorder(root);
    cout<< endl;
    cout<< "PREORDER"<< endl;
    preorder(root);
    cout<< endl;
    cout<< "POSTORDER"<< endl;
    postorder(root);
    cout<< endl;
    cout<< "LEVELORDER"<< endl;
    levelorder(root);
    cout<< endl;
    cout<< "LEVELORDER TRAVERSAL"<< endl;
    levelordertraversal(root);
    cout<< endl;



}
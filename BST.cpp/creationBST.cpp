#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this-> data= data;
        this-> left= NULL;
        this-> right= NULL;
    }
};
Node* CreateBST(Node* root, int data){
    if(root == NULL){
        root= new Node(data);
        return root;
    }
    if(data< root-> data){
        root-> left= CreateBST(root-> left, data);
    }
    if(data> root-> data){
        root-> right= CreateBST(root-> right, data);
    }
    return root;
}
void preorder(Node* root){
    if(root== NULL){
        return;
    }
    cout<< root-> data<< " ";
    preorder(root-> left);
    preorder(root-> right);
}
void inorder(Node* root){
    if(root== NULL){
        return;
    }
    inorder(root-> left);
    cout<< root-> data<< " ";
    inorder(root-> right);
}
void postorder(Node* root){
    if(root== NULL){
        return;
    }
    postorder(root-> left);
    postorder(root-> right);
    cout<< root-> data<< " ";
}
void levelordertraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* newnode= q.front();
        q.pop();
        if(newnode!= NULL){
            cout<< newnode-> data<< " ";
            if(newnode-> left!= NULL){
                q.push(newnode-> left);
            }
            if(newnode-> right!= NULL){
                q.push(newnode-> right);
            }
        }
        else {
            cout<< endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}
void takeInput(Node* &root){
    int data;
    cout<< "Enter the data"<< endl;
    cin>> data;
    while(data!= -1){
        root= CreateBST(root, data);
        cout<< "Enter the data"<< endl;
        cin>> data;
    }
}
int main(){
    Node* root= NULL;
    takeInput(root);
    inorder(root);
   

}
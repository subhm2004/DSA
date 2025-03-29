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
Node* InserttoBST(Node* root, int data){
    if(root== NULL){
        // create first node
        root= new Node(data);
        return root;
    }
    if(root-> data< data){
        root-> right= InserttoBST(root-> right, data);
    }
    if(root-> data> data){
        root-> left= InserttoBST(root-> left, data);
    }
    return root;
}
void takingInput(Node* &root){
    int data;
    cout<< "Enter data"<< endl;
    cin>> data;
    while(data!= -1){
        root= InserttoBST(root, data);
        cout<< "Enter data"<< endl;
        cin>> data;
    }
}
void ConverttoDLL(Node* root,Node* &head){
    if(root== NULL){
        return;
    }
    // right part is converted to DLL
    ConverttoDLL(root-> right, head);
    root-> right= head;
    if(head!= NULL){
        head-> left= root;
    }
    head= root;
    // left part is converted to DLL
    ConverttoDLL(root-> left, head);
}
void LevelOrderTraversal(Node* root){
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
void inorder(Node* root){
    if(root== NULL){
        return;
    }
    inorder(root-> left);
    cout<< root-> data<< " ";
    inorder(root-> right);
}
int main(){
    Node* root= NULL;
    takingInput(root);
    LevelOrderTraversal(root);
    cout<< endl;
}
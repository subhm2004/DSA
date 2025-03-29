// Create a BST from inorder traversal
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
Node* CreateBSTInorder(int inorder[], int s, int e, int& size){
    if(s>=e){
        return NULL;
    }
    int mid= s+(e-s)/2;
    Node* root= new Node(inorder[mid]);
    root-> left=  CreateBSTInorder(inorder, s, mid-1, size);
    root-> right= CreateBSTInorder(inorder, mid+1, e, size);
    return root;

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
int main(){
    int inorder[]= {5,10,15,20,25,30,35,40};
    int size= 8;
    int s=0;
    int e= size-1;
    Node* root= CreateBSTInorder(inorder, s,e, size);
    levelordertraversal(root);
}
#include<iostream>
#include<queue>
#include<map>
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
Node* CreateTree(){
    int data;
    cout<< "Enter data"<< endl;
    cin>> data;
    if(data==-1){
        return NULL;
    }
    Node* root= new Node(data);
    root-> left= CreateTree();
    root-> right= CreateTree();
    return root;
}
void leftboundary(Node* root){
    if(root== NULL){
        return;
    }
    if(root-> left == NULL && root-> right== NULL){ // leaf node pr aagye
        return;
    }
    cout<< root-> data<< " ";
    if(root-> left!= NULL){
        leftboundary(root-> left);
    }
    else {
        leftboundary(root-> right);
    }
}
void rightboundary(Node* root){
    if(root== NULL){
        return;
    }
    if(root-> left== NULL && root-> right== NULL){
        return;
    }
    if(root-> right!= NULL){
        rightboundary(root-> right);

    }
    else {
        rightboundary(root-> left);
    }
    // niche se upar nodes print karni h 
    cout<< root-> data<< " ";
}
void leafboundary(Node* root){
    if(root== NULL){
        return;
    }
    if(root-> left== NULL && root-> right== NULL){
        cout<< root-> data<< " ";
    }
    leafboundary(root-> left);
    leafboundary(root-> right);
}
void boundarytraversal(Node* root){
    if(root== NULL){
        return;
    }
    leftboundary(root);
    leafboundary(root);
    if(root-> right!= NULL){
        rightboundary(root-> right);
    }
    if(root-> left!= NULL){
        rightboundary(root-> left);
    }
}
int main(){
    Node* root= CreateTree();
    boundarytraversal(root);
}
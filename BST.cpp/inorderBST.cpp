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
Node* CreateBST(int inorder[], int s, int size, int e){
    if(s>e){
        return NULL;
    }
    int mid= s+(e-s)/2;
    
    Node* root= new Node(inorder[mid]);
    root-> left = CreateBST(inorder, s, size, mid-1);
    root-> right= CreateBST(inorder, mid+1, size, e);
    return root;

}
int main(){
    int inorder[]= {10,20,30,40,50,60,70};
    int size= 7;
    int s=0; 
    int e= size-1;
    Node* root= CreateBST(inorder, s, size, e);
    levelordertraversal(root);
}
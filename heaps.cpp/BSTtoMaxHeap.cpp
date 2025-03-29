// you are given a tree that is CBT and BST, 
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
Node* InsertIntoBST(Node* root, int data){
    if(root== NULL){
        root= new Node(data);
        return root;
    }
    if(root-> data> data){
        root-> right= InsertIntoBST(root-> right, data);
    }
    if(root-> data< data){
        root-> left= InsertIntoBST(root-> left, data);
    }
    return root;

}
void CreateBST(Node* root){
    int data;
    cout<< "enter data"<< endl;
    cin>> data;
    while(data!= -1){
        root = InsertIntoBST(root, data);
        cout<< "Enter data"<< endl;
        cin>> data;
    }
}
void levelordertraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* newnode= q.front();
        q.pop();
        if(newnode!= NULL){
            cout<< newnode-> data<< endl;
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
    Node* root= NULL;
}
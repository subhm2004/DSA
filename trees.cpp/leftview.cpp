// print the left view of a tree
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
Node* Createtree(){
    int data;
    cout<< "Enter data"<< endl;
    cin>> data;
    if(data == -1){
        return NULL;
    }
    Node* root= new Node(data);
    root-> left= Createtree();
    root-> right= Createtree();
    return root;

}
void levelordertraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    cout<< q.front()-> data<< endl;
    while(!q.empty()){
        Node* newnode= q.front();
        q.pop();
        if(newnode!= NULL){
            if(newnode-> left!= NULL){
                q.push(newnode-> left);
            }
            if(newnode-> right!= NULL){
                q.push(newnode-> right);
            }
        }
        else { 

            if(!q.empty()){
                cout<< q.front()-> data<< endl;
                q.push(NULL);
            }
            
        }
    }
}
void printleftview(Node* root, vector<int>&leftview, int level){
    if(root == NULL){
        return;
    }
    if(level== leftview.size()){
        leftview.push_back(root-> data);  
    }
    printleftview(root-> left, leftview, level+1);
    printleftview(root-> right, leftview, level+1);
}
void printrightview(Node* root, vector<int>&right, int level){
    if(root== NULL){
        return;
    }
    if(right.size()== level){
        right.push_back(root-> data);
    }
    printrightview(root-> right, right, level+1);
    printrightview(root-> left, right, level+1);
}
int main(){
    Node* root= Createtree();
    int level=0;
    vector<int>right;
    printrightview(root, right,level);
    for(int i=0; i<right.size(); i++){
        cout<< right[i]<< " ";
    }

    
}
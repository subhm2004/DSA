#include<iostream>
#include<map>
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
void topview(Node* root){
    map<int,int>distNode;
    queue<pair<Node*,int>>q;
    // push first elemnet in queue
    q.push(make_pair(root,0));
    // level order traversal
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int level= temp.second;
        // particular level ki entry find karne ki koshish akr rhe h  
        if(distNode.find(level)== distNode.end()){
            distNode[level]= frontNode-> data;
        }
        // left and right subtree
        if(frontNode-> left!= NULL){
            q.push(make_pair(frontNode-> left, level-1));
        }
        if(frontNode-> right!= NULL){
            q.push(make_pair(frontNode-> right, level+1));
        }
    }
    cout<< "Top view"<< endl;
    for(auto i: distNode){
        cout<< i.second<< " ";
    }
}
void bottomview(Node* root){
    map<int, int>distNode;
    queue<pair<Node*, int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node*, int>temp= q.front();
        q.pop();
        Node* frontNode= temp.first;
        int level= temp.second;
        distNode[level]= frontNode-> data;
        // left and right subtrees
        if(frontNode-> left!= NULL){
            q.push(make_pair(frontNode-> left, level-1));
        }
        if(frontNode-> right!= NULL){
            q.push(make_pair(frontNode-> right, level+1));
        }
    }
    cout<< "Bottom View"<< endl;
    for(auto i: distNode){
        cout<< i.second << " ";
    }        
}
int main(){
    Node* root= CreateTree();
    bottomview(root);
}
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
void levelorder(Node* root){
    queue<Node*>q;
    q.push(root);
    Node* temp= q.front();
    while(!q.empty()) {
        if(temp== root) q.pop();
        if(temp== NULL){
            temp= q.front();
            q.pop();
        }       
        cout<< temp-> data<< " ";
        if(temp-> left!= NULL){
            q.push(temp-> left);
        }
        if(temp-> right!= NULL){
            temp= temp-> right;
        }
        else {
            temp= NULL;
        }
    }
}
int main(){
    Node* root= CreateTree();
    cout<< "printing diagonal traversal"<< endl;
    levelorder(root);
}
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
void levelordertraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* newnode= q.front();
        q.pop();
        if(newnode!= NULL){
            cout<< newnode-> data;
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
void levelleftview(Node* root){
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
                q.push(NULL);
                cout<< q.front()-> data<< endl;
            }
        }
    }
}
void leftviewrecursion(Node* root, vector<int>&left, int level){
    if(root== NULL){
        return;
    }
    if(left.size()== level){
        left.push_back(root-> data);
    }
    leftviewrecursion(root-> left, left,level+1);
    leftviewrecursion(root-> right, left,level+1);
}
void rightviewrecursion(Node* root, vector<int>&right, int level){
    if(root== NULL)
{
    return;
}
    if(right.size()== level){
        right.push_back(root-> data);
    }
    rightviewrecursion(root-> right, right, level+1);
    rightviewrecursion(root-> left, right, level+1);
}
int main(){
    Node* root= CreateTree();
    vector<int>right;
    int level=0;
    rightviewrecursion(root, right, level);
    for(int i=0; i<right.size(); i++){
        cout<< right[i]<< " ";
    }
}

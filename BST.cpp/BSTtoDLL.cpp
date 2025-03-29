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
    if(data == -1){
        return NULL;
    }
    Node* root= new Node(data);
    root-> left= CreateTree();
    root-> right= CreateTree();
    return root;
}
void levelorderTraversal(Node* root){
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
void converttoDLL(Node* root, Node* &head){
    if(root== NULL){
        return;
    }
    // right part ko DLL me convert karo
    converttoDLL(root-> right, head);
    // attach root node
    root-> right= head;
    if(head!= NULL){
        head-> left= root;
    }
    // update head
    head= root;
    // left subtree
    converttoDLL(root-> left, head);
}
void printLL(Node* head){
    cout<< "Printing double linkedlist"<< endl;
    Node* temp= head;
    while(temp!= NULL){
        cout<< temp-> data<< "->";
        temp= temp-> right;
    }
    cout<< endl;
}
int main(){
    Node* root= CreateTree();
    levelorderTraversal(root);
    Node* head= NULL;
    converttoDLL(root, head);

}
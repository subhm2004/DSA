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
Node* CreateBST(Node* root, int data){
    if(root== NULL){
        // CREATING FIRST NODE
        root= new Node(data);
        return root;
    }
    if(data> root-> data){
        root-> right= CreateBST(root-> right, data);
    }
    else {
        root-> left= CreateBST(root-> left, data);
    }
    return root;
}
void takinginput(Node* &root){
    int data;
    cout<< "Enter data"<< endl;
    cin>>data;
    while(data!= -1){
        root= CreateBST(root, data);
        cout<< "Enter data"<< endl;
        cin>> data;
    }
}
Node* searchInBST(Node* root, int target){
    if(root == NULL){
        return NULL;
    }
    if(root-> data== target){
        return root;
    }
    else if(root-> data> target){
        return searchInBST(root-> left, target);
    }
    else {
        return searchInBST(root-> right, target);
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
int FindMaximum(Node* root){
    if(root== NULL){
        return -1;
    }
    while(root-> right!= NULL){
        root= root-> right;
    }
    return root-> data;

}

// deletion- 4 cases -> leaf node, node with only right child,
// node with only left child, node with both child
Node* deletionInBST(Node* root, int target){
    if(root== NULL){
        return NULL;
    }
    if(root-> data == target){
        // 4 cases 
         if(root-> left== NULL && root-> right== NULL){
        // Leaf node h
        delete root;
        return NULL;
    }
    else if(root-> left!= NULL && root -> right== NULL){
        Node* child= root-> left;
        delete root;
        return child;
    }
    else if(root-> left== NULL && root-> right!= NULL){
        Node* child= root-> right;
        delete root;
        return child;
    }
    else {
        // Inorder predecessor ya successor ko lekar aao
        int child = FindMaximum(root-> left);
        root-> data= child;
        root-> left = deletionInBST(root-> left, child);
        return root;
    }

    }
    else if(root-> data > target){
        root-> left= deletionInBST(root-> left,target);
    }
    else {
        root-> right= deletionInBST(root-> right, target);
    }
    
}
int main(){
    Node* root= NULL;
    takinginput(root);
    int target;
    cout<< " Enter the node to be deleted"<< endl;
    cin>> target;
    deletionInBST(root, target);
    levelordertraversal(root);

}
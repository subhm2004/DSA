#include<iostream>
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
bool searchInBST(Node* root, int target){
    if(root== NULL){
        return false;
    }
    if(root-> data== target){
        return true;
    }
    else if(root-> data > target){
        return searchInBST(root-> left, target);
    }
    else {
        return searchInBST(root-> right, target);
    }
}
int FindMinimum(Node* root){
    if(root== NULL){
        return -1;
    }
    while(root-> left!= NULL){
        root= root-> left;
    }
    return root-> data;
}
int FindMaxNode(Node* root){
    if(root== NULL){
        return -1;
    }
    while(root-> right!= NULL){
        root= root-> right;
    }
    return root-> data;
}

int main(){
    Node* root= NULL;
    takinginput(root);
    int ans= FindMinimum(root);
    int ans2= FindMaxNode(root);
    cout<< "Minimum Value: "<< ans<< endl;
    cout<< "Maximum Value: "<< ans2<< endl;
    // int target;
    // cout<< "Enter target"<< endl;
    // cin>> target;
    // bool ans= searchInBST(root, target);
    // cout<< " node present or not "<< ans<< endl;

}
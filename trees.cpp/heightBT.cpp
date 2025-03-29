#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this-> data= val;
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
    // create node
    Node* root= new Node(data);
    // create left subtree
    root-> left= CreateTree();
    // crete right subtree
    root-> right= CreateTree();
    return root;
}
int Maxdepth(Node* root){
    // base case
    if(root== NULL){
        return 0;
    }
    int left= Maxdepth(root->left);
    int right= Maxdepth(root-> right);
    int maxi= max(left,right);
    return maxi+1;

}
int main(){
    Node* root= CreateTree();


}
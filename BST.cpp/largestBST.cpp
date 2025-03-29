// find the largest BST in Binary tree
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
class NodeData{
    public:
    int size;
    int minval;
    int maxval;
    bool validBST;
    NodeData(){

    }
    NodeData(int size, int min, int max, bool valid){
        this-> size= size;
        minval= min;
        maxval= max;
        validBST= valid;
    }
};
NodeData findlargest(Node* root, int& ans){
    if(root== NULL){
        NodeData temp (0,INT_MAX, INT_MIN, true);
        return temp;
    }
    NodeData left= findlargest(root-> left, ans);
    NodeData right= findlargest(root-> right, ans);
    // processing current Node
    NodeData currNode;
    currNode.size= left.size + right.size +1;
    currNode.maxval= max(right.maxval, root-> data);
    // these are max and min values abhi tak k tree ki including current Node 
    currNode.minval= min(root-> data, left.minval);
    if(left.validBST && right.validBST && (root-> data> left.maxval && root-> data< right.minval)){
        currNode.validBST= true;
    }
    // 4 conditions check karne k baad answer return karo
    if(currNode.validBST){
        ans= max(ans, currNode.size);
    }
    return currNode;

}
Node* CreateBST(Node* root, int data){
    if(root== NULL){
        // create first node
        root= new Node(data);
    }
    if(data> root-> data){
        root-> right= CreateBST(root-> right, data);
    }
    else if(data < root-> data){
        root-> left= CreateBST(root-> left, data);
    }
    return root;
}
void TakeInput(Node* root){
    int data;
    cout<< "Enter data"<< endl;
    cin>> data;
    while(data!= -1){
        root= CreateBST(root, data);
        cout<< "Enter data"<< endl;
        cin>> data;
    }
}

int main(){
    Node* root= NULL;
    int ans=0;
    findlargest(root, ans);

}
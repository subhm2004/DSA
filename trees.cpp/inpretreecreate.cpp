#include<iostream>
#include<queue>
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
void levelorder(Node* root) {
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
            q.push(NULL);
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}
int searchinorder(int inorder[], int size, int target){
    for(int i=0; i< size; i++){
        if(inorder[i] == target){
            return i;
        }
    }
    return -1;
}
Node* createtreeprein(int preorder[], int &preorder_index, int size, int inorder[], int inorder_start, int inorder_end){
    if(preorder_index >= size|| inorder_start > inorder_end){
        return NULL;
    }
    // 1 case solve kro
    int element= preorder[preorder_index];
    preorder_index++;  
    Node* root= new Node(element);
    int position= searchinorder(inorder, size, element);
    // root ke left me elemnets place karo
    root-> left= createtreeprein(preorder, preorder_index, size, inorder, inorder_start, position-1);
    root-> right= createtreeprein(preorder,preorder_index, size, inorder, position +1, inorder_end);
    return root;
}
int main(){
    int preorder[]= {2,8,10,6,4,12};
    int inorder[]= {10,8,6,2,4,12};
    int size= 6;
    int preorder_index= 0;
    int inorder_start=0;
    int inorder_end= 5;
    Node* root= createtreeprein(preorder, preorder_index, size, inorder, inorder_start, inorder_end);
    cout<< "Printing tree"<< endl;
    levelorder(root);

}
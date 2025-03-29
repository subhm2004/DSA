#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
bool levelordertraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    bool flag = false;
    while(!q.empty()){
        Node* newnode= q.front();
        q.pop();
        if(newnode== NULL){
            flag= true;
        }
        else {
            if(flag== true){
                return false;
            }
            q.push(newnode-> left);
            q.push(newnode-> right);
        }
    }
    return true;
}
bool CheckCBT(Node* root){
    levelordertraversal(root);


}
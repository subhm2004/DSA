#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};
class Valid{
    public:
    int maxVal;
    bool IsHeap;
};
Valid CheckMaxHeap(Node* root){
    if(root== NULL){
        Valid temp;
        temp.maxVal= INT_MIN;
        temp.IsHeap= true;
        return temp;
    }
    if(root-> left== NULL && root-> right== NULL){
        Valid temp;
        temp.maxVal= root-> data;
        temp.IsHeap= true;
        return temp;
    }
    Valid left= CheckMaxHeap(root-> left);
    Valid right= CheckMaxHeap(root-> right);
    if(root-> data> left.maxVal && root-> data> right.maxVal && left.IsHeap && right.IsHeap){
        Valid temp;
        temp.maxVal= root-> data;
        temp.IsHeap= true;
        return temp;
    }
    else {
        Valid temp;
        temp.maxVal= max(root-> data, max(left.maxVal, right.maxVal));
        temp.IsHeap= false;
        return temp;
    }
}
int main(){
    Node* root= NULL;
}
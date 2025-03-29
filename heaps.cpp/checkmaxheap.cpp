// check whether a CBT is Max heap or not
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
class Valid{
    public:
    int maxVal;
    bool isHeap;
    Valid(){

    }
};
Valid CheckMaxHeap(Node* root){
    // base cases
    if(root== NULL){
        Valid temp;
        temp.maxVal= INT_MIN;
        temp.isHeap= true;
        return temp;
    }
    if(root-> left== NULL && root-> right== NULL){
        // leaf node
        Valid temp;
        temp.maxVal= root-> data;
        temp.isHeap= true;
        return temp;

    }
    // recursion 
    Valid left= CheckMaxHeap(root-> left);
    Valid right= CheckMaxHeap(root-> right);
    if(root-> data> left.maxVal && root-> data> right.maxVal && left.isHeap && right.isHeap){
        Valid temp;
        temp.maxVal= root-> data;
        temp.isHeap= true;
        return temp;
    }
    else {
        Valid temp;
        temp.maxVal= max(root-> data, max(left.maxVal, right.maxVal));
        temp.isHeap= false;
        return temp;
    }
}
int main(){

}
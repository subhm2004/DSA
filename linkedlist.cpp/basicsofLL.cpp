#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next; // pointer of node* type
    Node(){ 
        cout<< "this is default ctor"<< endl;
        this-> next= NULL;
    }
    // parametrised ctor
    Node(int data){
        this-> data= data;
        this-> next= NULL;
    }
};
void printll(Node* head){
    Node* temp= head;
    while(temp!=NULL){
        cout<< temp-> data<< "->";
        temp= temp-> next;
    }
    cout<< endl;
}
void printingLL(Node* head){
    if(head==NULL){
        return;
    }
    Node* temp= head;
    cout<< temp->data<< "-> ";
    printingLL(head-> next);
    // cout<< temp->data<< "-> ";
}
// printing number of nodes in a linkedlist
int nodesinll(Node*head, int count){
    if(head==NULL){
        return count;
    }
    return nodesinll(head-> next, count+1);
}
// number of nodes using loop
int nodecount(Node* head, int count){
    Node* temp= head;
    while(temp!=NULL){
        temp= temp-> next;
        count++;
    }
    return count;
}
void insertatbegin(Node* &head, int data){ // head is pass by refernce here
    Node* newnode= new Node(data);// nyi node bna li
    Node* temp = head;
    if(temp==NULL){
        temp = newnode;
    }
    else{
        newnode->next= temp;
    }
    head = newnode;   
}

int main(){
    // creating object dynamically
    //Node* a= new Node();default ctor called in this case
    int data;
    Node* first= new Node(10);
    Node* second= new Node(20);
    Node* third= new Node(30);
    Node* fourth= new Node(40);
    Node* fifth= new Node(50);
    // linking the nodes:
    first-> next= second;
    second-> next= third;
    third-> next= fourth;
    fourth-> next= fifth;
    Node* head= first;
    cout<< "enter data of newnode"<< endl;
    cin >> data;
    insertatbegin(head,data);
    printingLL(head);
    cout<< endl;
    return 0;
}

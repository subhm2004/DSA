// check if a linkedlist is pallindrome
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this-> data=0;
        this-> next= NULL;
    }
    Node(int data){
        this-> data= data;
        this-> next= NULL;
    }
};
Node* midnode(Node* &head, Node* &tail){
    Node* slow= head;
    Node* fast= head;
    while(fast-> next!= NULL){
        fast= fast-> next;
        if(fast-> next!= NULL){
            fast= fast-> next;
            slow= slow-> next;
        }
    }
    return slow;
}
void reversell(Node* prev, Node* current, Node* &head2){
    if(current== NULL){
        head2 = prev;
        return;
    }
    Node* temp= current-> next;
    current-> next= prev;
    reversell(current, temp, head2);
}
void comparell(Node* &head, Node* &head2){
    Node* ptr1= head;
    Node* ptr2= head2;
    while(head!= NULL && head2!= NULL){
        if(ptr1-> data == ptr2-> data){
            ptr1= ptr1-> next;
            ptr2= ptr2-> next;
        }
        else {
            cout<<  false;
        }
    }
    cout<< true;
}
void traversal(Node* &head){
    Node* temp= head;
    while(temp!= NULL){
        cout<< temp-> data<< " -> ";
        temp= temp-> next;
    }
    cout << endl;
}
void insertathead(Node* &head, Node* &tail, int data){
    if(head== NULL){
        Node* newnode= new Node(data);
        head= newnode;
        tail= newnode;
    }
    else{
        Node* newnode = new Node(data);
        newnode-> next= head;
        head= newnode;
    }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,1);
    insertathead(head,tail,2);
    insertathead(head,tail,3);
    insertathead(head,tail,3);
    insertathead(head,tail,2);
    insertathead(head,tail,1);
    traversal(head);
    Node* middle = midnode(head,tail);
    cout<< middle-> data<< endl;
    Node* head2 = middle -> next;
    middle-> next = NULL;
    // Linked list do part me divide ho chuki h
    // reverse second linkedlist
    Node* prev= NULL;
    Node* current= head2;
    reversell(prev,current,head2);
    traversal(head2);
    comparell(head,head2);
    
}
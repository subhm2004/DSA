#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        this-> data= 0;
        this-> next= NULL;
    }
    Node(int data){
        this-> data= data;
        this-> next= NULL;
    }
};
void traversalLL(Node* &head, Node* &tail){
    Node* temp= head;
    while(temp!= NULL){
        cout<< temp-> data << "-> ";
        temp= temp-> next;
    }
    cout<< endl;
}
void insertathead(Node* &head, Node* &tail, int data){
    if(head== NULL){
        // no node present
        Node* newnode= new Node(data);
        head= newnode;
        tail= newnode;
    }
    else {
        Node* newnode = new Node(data);
        newnode-> next= head;
        head= newnode;
    }
}
void insertattail(Node* &head, Node* &tail, int data){
     if(head== NULL){
        // no node present
        Node* newnode= new Node(data);
        head= newnode;
        tail= newnode;
    }
    else {
        Node* newnode= new Node(data);
        tail-> next= newnode;
        tail= newnode;
    }
}
void reversell(Node* &head, Node* &tail){
    Node* current= head;
    Node* prev= NULL;
    while(current!= NULL){
        Node* temp= current-> next;
        current-> next= prev;
        prev= current;
        current= temp;
    }
    head= prev;   
}
int lengthLL(Node* &head){
    Node* temp= head;
    int count=0;
    while(temp!= NULL){
        count++;
        temp= temp-> next;
    }
    return count;   
}
// tortoise algorithm-> for finding midnode
Node* findmidnode(Node* &head, Node* &tail){
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
// check if the linkedlist is pallindrome or not
bool pallindrome(Node* &head, Node* &tail){
    Node* midnode = findmidnode(head, tail);
    Node* head2 = midnode-> next;
    midnode-> next = NULL;
    reversell(head2,tail);
    // comparison ka logic
    Node* temp = head;
    Node* temp2 = head2;
    while(temp!= NULL && temp2!= NULL){
        if(temp-> data == temp2-> data){
            temp= temp-> next;
            temp2= temp2-> next;
        }
        else {
            return false;
        }
    }
    return true;
}
void deletioninLL(Node* &head, Node* &tail, int& position){
    if(head == NULL){
        // nothing to delete
        cout<< "Can't delete"<< endl;
        return;
    }
    if(head == tail){
        Node* temp= head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    // delete at head
    if(position == 1){
        // delete from head
        Node* temp = head;
        head= head-> next;
        temp -> next = NULL;
        delete temp;
    }
    else if (position == lengthLL(head)){
        // deleting the last node
        Node* temp = head;
        while(temp-> next != tail){
            temp= temp-> next;
        }
        temp-> next= NULL;
        delete tail;
        tail= temp;
    }
    else{
        Node* temp= head;
        Node* ptr= head-> next;
        int i=1;
        while(i!= position-1){
            temp= temp-> next;
            ptr= ptr-> next;
            i++;
        }
        temp-> next= ptr-> next;
        ptr-> next= NULL;
        delete ptr;
    }
}
int main(){
    int position;
    cout<< "enter position"<< endl;
    cin>> position;
    Node* head= NULL;
    Node* tail= NULL;
    insertathead(head,tail,10);
    insertathead(head,tail,20);
    insertathead(head,tail,30);
    insertathead(head,tail,40);
    insertathead(head,tail,50);
    insertathead(head,tail,60);
    traversalLL(head,tail);
    deletioninLL(head,tail,position);
    traversalLL(head,tail);
}
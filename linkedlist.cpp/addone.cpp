// you are given a linkedlist, add one to it n return the sum 
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
void reversal(Node* &head, Node* &prev, Node* &current){
    if(current ==NULL){
        head= prev;
        return;
    }
    Node* temp= current-> next;
    current -> next= prev;
    reversal(head,current,temp);
}
void addonetoLL(Node* &head,  Node* &prev, Node* &current){
    reversal(head,prev,current);
    Node* ptr= head;
    while(ptr!= NULL){
        if(ptr-> data==9){
            if(ptr-> next== NULL){
                Node* newnode= new Node(1);
                ptr-> next= newnode; 
                ptr-> data=0;
                ptr= ptr-> next;
                break;   
            }
            ptr-> data=0;
            ptr= ptr-> next;
        }
        else {
            ptr-> data= ptr-> data +1;
            break;
        }
    }
    prev= NULL;
    current= head;
    reversal(head,prev,current);    
}
void addone(Node* &head, Node* &prev, Node* &current){
    reversal(head,prev,current);
    Node* temp= head;
    int carry= 1;
    while(temp!= NULL){
        int totalsum= temp-> data+ carry;
        int digit= totalsum % 10;
        carry= totalsum/10;
        temp-> data= digit;
        if(carry==1 && temp-> next== NULL){
            Node* newnode = new Node(carry);
            temp-> next= newnode;
            break;
        }
        if(carry==0){
            break;
        }
        temp= temp-> next;
    }
    prev= NULL;
    current= head;
    reversal(head,prev,current);
}
int main(){
    Node* head= NULL;
    Node* tail= NULL;
    insertathead(head,tail,9);
    insertathead(head,tail,9);
    insertathead(head,tail,9);
    insertathead(head,tail,9);  
    Node* current= head; 
    Node* prev= NULL;
    addone(head,prev,current);
    traversal(head);
}
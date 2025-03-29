#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        // default ctor
        this-> data=0;
        this-> next= NULL;
    }
    Node(int data){
        // parameterised ctor
        this-> data= data;
        this-> next= NULL;
    }
    ~Node() {
        cout<< "destructor called for "<< this-> data << endl;
    }
};
void traversalLL(Node* &head){
    Node* tem = head;
    while(tem!= NULL){
        cout<< tem-> data<< "-> ";
        tem = tem-> next;
    }
}
void insertathead(Node* &head,Node* &tail,int data){
    Node* newnode= new Node(data);
    if(head== NULL){
        head= newnode;
        tail= newnode;
    }
    else {
        newnode-> next = head;
        head= newnode;
    }
}
void insertattail(Node* &head, Node* &tail, int data){
    if(head== NULL){
        Node* newnode= new Node(data);
        head= newnode;
        tail= newnode;
    }
    else {
        Node* newnode= new Node(data);
        tail-> next = newnode;
        tail= newnode;
    }
}
void deletehead(Node* &head){
    if(head== NULL){
        cout<< "Can't delete" << endl;
    }
    else {
        Node* temp = head;
        head= temp-> next;
        temp-> next = NULL;
        delete temp;    
    }
}
void deletetail(Node* &head, Node* &tail){
    if(head== NULL){
        cout<< "Can't delete"<< endl;
    }
    else{
        Node* temp = head;
        while(temp-> next != tail){
            temp = temp-> next;
        }
        Node* ptr= tail;
        cout<< "element deleted is "<< ptr-> data<< endl;
        tail= temp;
        tail-> next= NULL;
        delete ptr;
    }
}
int numofnodes(Node* &head, Node* &tail){
    int count = 1;
    Node* temp = head;
    while(temp-> next!= NULL){
        count++;
        temp= temp-> next;
    }
    return count;
}
void deletemiddle(Node* &head, Node* &tail, int &index){
    if(index> numofnodes(head,tail) || index<1){
        cout<< "Invalid Index for deletion "<< endl;
        return;
    }
    else if(head==  tail){
        Node* temp = head;
        delete temp;
        head= NULL;
        tail= NULL;
    }
    else if(index==1){
        // delete first node
        Node* temp = head;
        head= head-> next;
        temp-> next = NULL;
        delete temp;
    }
    else if(index == numofnodes(head,tail)){
        // delete the last node
        Node* temp= head;
        while(temp-> next!= tail){
            temp= temp-> next;
        }
        Node* ptr= tail;
        tail= temp;
        temp-> next= NULL;
        delete ptr;
    }
    else {
        int i=1;
        Node* temp = head;
        Node* ptr= head-> next;
        while(index-1!=i){
            i++;
            temp= temp-> next;
            ptr= ptr-> next;
        }
        temp->next= ptr-> next;
        ptr-> next = NULL;
        delete ptr;
    }
}
int main(){
    int index;
    cout<< "enter the index to be deleted"<< endl;
    cin>> index;
    Node* head= NULL;
    Node* tail= NULL;
    insertathead(head,tail,10);
    insertathead(head,tail,30);
    insertathead(head,tail,50);
    insertathead(head,tail,70);
    traversalLL(head);
    cout<< endl;
    deletemiddle(head,tail,index);
    traversalLL(head);
}
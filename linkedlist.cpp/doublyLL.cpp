#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        cout<< "default ctor called"<< endl;
        this-> data=0;
        this-> prev= NULL;
        this-> next= NULL;
    }
    Node(int data){
        this-> data= data;
        this-> prev= NULL;
        this-> next= NULL;
        cout<< "parameterised ctor for "<< this-> data<<  endl;
    }
};
void doublyll(Node* &head, Node* &tail){
    // forward traversal
    Node* temp = head;
    while(temp!= NULL){
        cout<< temp-> data<< "-> ";
        temp = temp-> next;
    }
    cout<< endl;
    // cout<< " reverse traversal "<< endl;
    // temp= tail;
    // while(temp!= NULL){
    //     cout<< temp-> data<< " <-";
    //     temp = temp-> prev;
    // }
    // cout<< endl;
}
int numofnodes(Node* &head, Node* &tail){
    Node* temp= head;
    int count=1;
    while(temp-> next!= NULL){
        count++;
        temp= temp-> next;
    }
    return count;
}
void insertdoublyll(Node* &head, Node* &tail, int &index, int &data){
    if(index<1 || index> numofnodes(head,tail)+1){
        cout<< "Invalid index for insertion"<< endl;
    }
    else if(index==1){
        // insertion at head
        Node* newnode= new Node(data);
        if(head== NULL){
            head= newnode;
        }
        else {
            newnode-> next= head;
            head-> prev= newnode;
            head= newnode;
        }
    }
    else if(index== numofnodes(head,tail)+1){
        // insertion at tail
        Node* newnode= new Node(data);
        if(tail== NULL){
            tail= newnode;
        }
        else{
            tail-> next= newnode;
            newnode-> prev= tail;
            tail= newnode;
        }
    }
    else{
        Node* newnode = new Node(data);
        Node* temp = head;
        Node* ptr= head-> next;
        int i=1;
        while(i!= index-1){
            temp= temp-> next;
            ptr= ptr-> next;
            i++;
        }
        temp-> next= newnode;
        newnode-> prev= temp;
        ptr-> prev= newnode;
        newnode-> next = ptr;

    }   
}
int main(){
    int index;
    cout<< " enter the index to perform insertion "<< endl;
    cin>> index;
    int data;
    cout<< "enter data"<< endl;
    cin>> data;
    Node* first= new Node(10);
    Node* second= new Node(20);
    Node* third= new Node(30);
    Node* fourth= new Node(40);
    Node* fifth= new Node(50);
    Node* head= first;
    Node* tail= fifth;
    // linking the nodes
    first-> next = second;
    second-> next= third;
    second-> prev= first;
    third-> next= fourth;
    third-> prev= second;
    fourth-> prev= third;
    fourth-> next = fifth;
    fifth-> prev= fourth;
    doublyll(head, tail);
    insertdoublyll(head,tail,index,data);
    doublyll(head,tail);
}
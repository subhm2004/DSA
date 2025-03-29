#include<iostream>
using namespace std;
class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(){
        this-> data=0;
        this-> next= NULL;
    }
    ListNode(int data){
        this-> data= data;
        this-> next= NULL;
    }
};
void traversal(ListNode* &head){
    ListNode* temp= head;
    while(temp!= NULL){
        cout<< temp-> data<< " -> ";
        temp= temp-> next;
    }
    cout << endl;
}
void insertathead(ListNode* &head, ListNode* &tail, int data){
    if(head== NULL){
        ListNode* newnode= new ListNode(data);
        head= newnode;
        tail= newnode;
    }
    else{
        ListNode* newnode = new ListNode(data);
        newnode-> next= head;
        head= newnode;
    }
}
void reversal(ListNode* prev, ListNode* current, ListNode* &head, ListNode* &tail){
    if(current == NULL){
        head= prev;
        return;
    }
    ListNode* temp= current-> next;
    current-> next= prev;
    reversal(current,temp,head,tail);
}
int main(){
    ListNode* head= NULL;
    ListNode* tail= NULL;
    insertathead(head,tail,12);
    insertathead(head,tail,10);
    insertathead(head,tail,8);
    insertathead(head,tail,6);
    insertathead(head,tail,4);
    insertathead(head,tail,2);
    traversal(head);
    ListNode* prev= NULL;
    ListNode* current= head;
    reversal(prev,current,head,tail);
    traversal(head);

}
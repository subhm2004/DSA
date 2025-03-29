// check loop
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

};
bool checkloop(Node* head){
    Node* slow= head;
    Node* fast= head;
    while(fast!= NULL){
        fast= fast-> next;
        if(fast!= NULL){
            fast= fast-> next;
            slow= slow-> next;
        }
        if(fast== slow){
            return true;
        }
    }
    return false;
}
Node* startingpoint(Node* head){
    Node* fast= head;
    Node* slow= head;
    while(fast!= NULL){
        fast= fast-> next;
        if(fast!= NULL){
            fast = fast-> next;
            slow = slow-> next;
        }
        if(fast == slow){
            fast = head;
            while(fast!= slow){
                fast= fast-> next;
                slow= slow-> next;
            }
            Node* start= slow;
           
        }
    }
}

int main(){
    
}
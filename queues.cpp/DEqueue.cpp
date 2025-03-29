#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int>dq;
    dq.push_back(10);
    dq.push_front(20);
    cout<< "Front: "<< dq.front()<< endl;
    cout<< "Rear: "<< dq.back()<< endl;
    cout<< "Size: "<< dq.size()<< endl;
}
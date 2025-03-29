#include<iostream>
#include<deque>
using namespace std;
void printfirstnegative(int *arr, int& size, int&k){
    deque<int>dq; // store the index of negative number
    for(int i=1; i<=k; i++){
        if(arr[i]<0){
            dq.push_back(i);
        }
    }
    // pehli window process hogyi
    for(int i=k+1; i<=size; i++){
        if(dq.empty()){
        cout<< 0<< " ";
        }
        else {
        cout<< arr[dq.front()]<< " ";
        }
        // removal
        if(i-dq.front()>=k){
            dq.pop_front();
        }
        // addition
        if(arr[i]<0){
            dq.push_back(i);
        }
    }
    // process last wali window alag se
    if(dq.empty()){
        cout<< 0<< " ";
    }
    else {
        cout<< arr[dq.front()]<< " ";
    }
}
int main(){
    int arr[]= {2,-5,4,-1,-2,0,5};
    int size= 7;
    int k=3; // window size
    printfirstnegative(arr,size,k);



}
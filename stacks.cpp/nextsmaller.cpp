// given an array, find the next smaller elemnet of the array
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void nextsmaller(int ans[], int& index, int& size, int arr[], stack<int>&sp){
    while(index>=0){
        if(!sp.empty() && (sp.top() < arr[index])) {
        ans[index]= sp.top();
        sp.push(arr[index]);
        index--;
        }
        else if (!sp.empty() &&  (sp.top() > arr[index])) {
            sp.pop();
        }
        else {
            ans[index]= -1;
        }
    }
}
int main(){
    int arr[]= {8,4,1,6,2,3};
    int size= 6;
    int index= size-1;
    int ans[6];
    stack<int>sp;
    sp.push(-1);
    nextsmaller(ans,index,size,arr,sp);
    for(int i=0; i< size; i++){
        cout<< ans[i]<< " ";
    }
}

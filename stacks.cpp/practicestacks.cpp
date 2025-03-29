// next smaller
#include<iostream>
#include<stack>
using namespace std;
void nextsmaller(int arr[], int ans[], int& size){
    int i= size-1;
    stack<int>st;
    st.push(-1);
    while(i>=0){
        if(!st.empty() && arr[i] > st.top()){
            ans[i]= st.top();
            st.push(arr[i]);
            i--;
        }
        else {
            st.pop();
        }
        
    }
    cout<< "{";
    for(int i=0; i< size; i++){
        cout<< ans[i]<< " ";
    }
    cout<< "}";
}
void prevsmaller(int arr[], int ans[], int& size){
    int i=0;
    stack<int>st;
    st.push(-1);
    while(i< size){
        if(!st.empty() && arr[i]> st.top()){
            ans[i]= st.top();
            st.push(arr[i]);
            i++;
        }
        else {
            st.pop();
        }
    }
    cout<< "{";
    for(int i=0; i< size; i++){
        cout<< ans[i]<< " ";
    }
    cout<< "}";

}

int main(){
    int arr[]= {8,4,6,2,3};
    int size= 5;
    int ans[5];
    prevsmaller(arr,ans,size);
}
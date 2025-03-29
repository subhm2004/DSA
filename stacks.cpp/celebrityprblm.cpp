// find the person who doesn't know anyone but everyone knows him
#include<iostream>
#include<stack>
using namespace std;
int celebrityperson(int arr[][3], int&n){
    stack<int>st;
    for(int i=0; i< n; i++){
        st.push(i);
    }
    while(st.size()!=1){
        int a= st.top();
        st.pop();
        int b= st.top();
        st.pop();
        if(arr[a][b]){
            st.push(b);
        }
        if(arr[b][a]) {
            st.push(a);
        }
    }
    int i= st.top();
    int j=0;
    while( j< n){
        if(arr[i][j]== 0 && (arr[j][i]== 1 && arr[i][i])==0){
            j++;  
        }
        else {
            return -1;
        }
    } 
    return i;  
}
int main() {
    int n=3;
    int arr[3][3]= {
        {0,1,0},
        {0,0,0},
        {0,1,0},
    };
    
    int ans= celebrityperson(arr,n);
    cout<< ans << endl;
    
}

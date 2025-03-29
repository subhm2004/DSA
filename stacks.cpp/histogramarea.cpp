// largest area in histogram
#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;
vector<int> nextsmaller(int heights[], int& size) {
    vector<int>ans(size);
    int i= size-1;
    stack<int>st;
    st.push(-1);
    while(i>=0){
        if(st.top() != -1 && heights[st.top()] < heights[i]){
            ans[i]= st.top();
            st.push(i);
            i--;
        }
        else {
            st.pop();
        }

    }
    return ans;
}
vector<int>prevsmaller(int heights[], int& size){
    vector<int>ans(size);
    int i=0;
    stack<int>st;
    st.push(-1);
    while(i< size-1){
        if(st.top() != -1 && heights[st.top()] < heights[i]){
            ans[i]= st.top();
            st.push(i);
            i++;
        }
        else {
            st.pop();
        }
    }
    return ans;
}
int largestarea(int heights[], int& size){
    vector<int>next= nextsmaller(heights,size);
    for(int i=0; i< size; i++){
        if(next[i]== -1){
            next[i]= size;
        }
    }
    vector<int>prev= prevsmaller(heights,size);
    vector<int>area(size);
    int maxi= INT_MIN;
    for(int i=0; i< size; i++){
        int width= next[i]- prev[i]-1;
        area[i] = heights[i]* width;
        maxi= max(maxi, area[i]);
    }
    return maxi;

}
int main(void){
    int heights[]= {2,1,5,6,2,3};
    int size= 6;

}
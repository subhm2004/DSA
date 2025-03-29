// online stock span problem- leetcode: 901
#include<iostream>
#include<utility>
#include<stack>
using namespace std;
stack<pair<int,int>>st;
int next(int price){
    int span=1;
    while(!st.empty() && st.top().first <= price){
        span= span + st.top().second;
        st.pop();
    }
    // current price ko push kiya kyuki vo kisi aur ka span nikalne me help kr skta h
    st.push({price,span});
    return span;
}
int main(){
    int price;
    cin>> price;
    int ans= next(price);
    cout<< ans;
}

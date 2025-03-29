#include<iostream>
#include<stack>
#include<string>
using namespace std;
void reversestack(stack<char>&st){
    stack<char>sp;
    while(!st.empty()){
        sp.push(st.top());
        st.pop();
    }
    while(!sp.empty()){
        cout<< sp.top();
        sp.pop();
    }
}
void removeduplicates(string& str, stack<char>&st){
    int i=0;
    st.push(str[i]);
    i++;
    while(i<str.length()){
        if(!st.empty() && str[i]== st.top()){
            st.pop();
        }
        else {
            st.push(str[i]);
        }
        i++;    
    }
    reversestack(st); 
       
}
int main(){
    string str = "azxxzy";
    stack<char>st;
    removeduplicates(str,st);

}
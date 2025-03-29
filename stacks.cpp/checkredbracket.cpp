#include<iostream>
#include<stack>
using namespace std;
bool redundantbracket(string &str, stack<char>&sp){
    int count=0;
    int index=0;
    while(index < str.length()){
        if(str[index]== '(' || str[index]== '+' || str[index]== '*' || str[index]== '-' || str[index]== '/'){
            sp.push(str[index]);
        }
        if(str[index]== ')'){
            count=0;
            while(!sp.empty() && sp.top() != '(') {
                if(sp.top()== '+' || sp.top()== '*' || sp.top()== '-' || sp.top()== '/'){
                count++;
                sp.pop();
                }
            }
            if(count == 0){
                return true;
            }
            
            sp.pop();
        }
        index++;
    }
    if(count!= 0){
        return false;
    }
}
int main(){
    string str= "((a+b)*((c)+d))";
    stack<char>sp;
    bool ans= redundantbracket(str,sp);
    cout<< ans<< endl;
}
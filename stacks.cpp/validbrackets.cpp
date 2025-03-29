#include<iostream>
#include<stack>
using namespace std;
bool checkparenthesis(string& str){
    int i=0;
    stack<char>sp;
    while(i< str.length()){
        if(str[i]== '('|| str[i]== '['|| str[i]== '{'){
            sp.push(str[i]);
        }
        else if(str[i]== ')'){
            if(sp.top()== '(' && !sp.empty()){
                sp.pop();
            }
            else {
                return false;
            }
        }
        else if(str[i]== '}' && !sp.empty()){
            if(sp.top()== '{'){
                sp.pop();
            }
            else {
                return false;
            }
        }
        else if(str[i]== ']' && !sp.empty()){
            if(sp.top()== '['){
                sp.pop();
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
        i++;

    }
    if(sp.empty()){
        return true;
    }
    else {
        return false;
    }
}
int main(){
    string str= "[{()}]";
    int n= str.length();
    bool ans= checkparenthesis(str);
    cout<< ans<< endl;
}

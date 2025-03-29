#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool validstr(string str, string& substr){
    while(!str.empty()){
        if(str.find(substr)== string::npos){
            return false;
        }
        else {
            int index= str.find(substr);
            str.erase(index,3);
        }
    }
    if(str.empty()){
        return true;
    }
    else {
        return false;
    }
}
int main(){
    string str= "ababcc";
    string substr= "abc";
    bool ans= validstr(str,substr);
    cout<< ans<< endl;
    
}